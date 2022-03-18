// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class BSCB_T1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AMyCharacter();

	
protected:
	virtual void BeginPlay() override;

	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Movement")
	float WalkSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Movement")
	float SprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Turning")
	float TurnAmount;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Jumping")
	bool BJumping;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash")
	float DashDistance;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash")
	float RollDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dash")
	bool HasUsedAbility;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash")
	float AbilityDuration;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash")
	float AbilityCoolDown;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash")
	UAnimMontage* DashAnim;
	
	FTimerHandle AbilityTimeHandler;
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
	void MoveForward(float Value);

	void MoveRight(float Value);
	
	void Turn(float Value);
	
	//sprinting ability
	void StartRun();

	void EndRun();
	
	//jump ability
	void Jumping();

	//crouching ability
	void Crouching();

	void StopCrouching();
	
	//dashing ability
	void Dashing();
	
	void ResetAbility();

	void AbilityComplete();
	
};
