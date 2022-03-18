// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


AMyCharacter::AMyCharacter()
{
	//constructor default values and setting up camera/varaibles
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;
	GetCharacterMovement()->bOrientRotationToMovement = true; 	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
 	WalkSpeed = 400.f;
	SprintSpeed = 600.f;
	TurnAmount = 0.0f;
	BJumping = false;
	DashDistance = 2000.0f;
	RollDistance = 2500.0f;
	HasUsedAbility = false;
	AbilityDuration = 1.0f;
	AbilityCoolDown = 2.0f;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->JumpZVelocity = 500.f;

	//Cameras Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 700.0f;
	SpringArm->TargetOffset = FVector(0.f, 000.f, 200.f);
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraLagSpeed = 10.0f;
	SpringArm->bUsePawnControlRotation; //camera will rotate with controller

	//Camera that follows player
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); //attaching camera to spring arm
	FollowCamera->bUsePawnControlRotation = false; //camera doesnt rotate relative to the spring arm
}


void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//Axis
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	
	//Actions 
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::StartRun);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::EndRun);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jumping);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::Jumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyCharacter::Crouching);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyCharacter::StopCrouching);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AMyCharacter::Dashing);
	
}



void AMyCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
    	{
    		
    		const FRotator Rotation = Controller->GetControlRotation();
    		const FRotator YawRotation(0, Rotation.Yaw, 0);
    		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    		AddMovementInput(Direction, Value);
			
    	}
}

void AMyCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		//Which way right - After this I then get the right vetor and apply movement to it
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
		
	}
}


void AMyCharacter::StartRun()
{
	GetCharacterMovement()->MaxWalkSpeed=SprintSpeed;
	UE_LOG(LogTemp, Warning, TEXT("Sprinting"));
	
}

void AMyCharacter::EndRun()
{
	GetCharacterMovement()->MaxWalkSpeed=WalkSpeed;
	UE_LOG(LogTemp, Warning, TEXT("Not Sprinting"));
}

void AMyCharacter::Jumping()
{
	Jump();
	UE_LOG(LogTemp, Warning, TEXT("Jumping"));
	
}

void AMyCharacter::Crouching()
{
	/*
	BJumping = false;
	//Crouch();
	if(DashAnim)
	{
		//Crouch();
		PlayAnimMontage(DashAnim, 1, NAME_None);
		const FVector ForwardCrouch = this->GetActorRotation().Vector();
		LaunchCharacter(ForwardCrouch * RollDistance, true, true);
		
	}
	*/
}

void AMyCharacter::StopCrouching()
{
	//UnCrouch();
}

void AMyCharacter::Dashing()
{
	
	if(!HasUsedAbility)
	{
		if(!GetCharacterMovement()->IsFalling())
		{
			HasUsedAbility = true;
			const FVector ForwardDir = this->GetActorRotation().Vector();
			LaunchCharacter(ForwardDir * DashDistance, true, true);
			GetWorld()->GetTimerManager().SetTimer(AbilityTimeHandler, this, &AMyCharacter::ResetAbility, AbilityDuration, false);
			UE_LOG(LogTemp, Warning, TEXT("Player Has Used Ability"));
		}
	}
}

void AMyCharacter::ResetAbility()
{
	GetWorld()->GetTimerManager().SetTimer(AbilityTimeHandler, this,&AMyCharacter::AbilityComplete, AbilityCoolDown, false);
	UE_LOG(LogTemp, Warning, TEXT("Ability is resetting"));
}

void AMyCharacter::AbilityComplete()
{
	HasUsedAbility = false;
	UE_LOG(LogTemp, Warning, TEXT("Ability reset"));
}



