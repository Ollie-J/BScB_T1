// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
	MovementSpeed = 400.0f;
	IsFalling = false;
}

void UMyAnimInstance::NativeInitializeAnimation()
{
	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
}

void UMyAnimInstance::UpdateAnimation()
{
	//check
	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if(Pawn)
	{
		//setting speed for player 
		FVector Speed = Pawn->GetVelocity();
		//ignoresZComp
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.0f);
		MovementSpeed = LateralSpeed.Size();
		IsFalling = Pawn->GetMovementComponent()->IsFalling();
	}
}
