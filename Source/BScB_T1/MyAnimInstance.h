// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BSCB_T1_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	public:
		UMyAnimInstance();
	
		virtual void NativeInitializeAnimation() override;

		UFUNCTION(BlueprintCallable, Category = "Anim")
		void UpdateAnimation();
	
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement");
		float MovementSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement");
		bool IsFalling;
	
		class APawn* Pawn;
};
