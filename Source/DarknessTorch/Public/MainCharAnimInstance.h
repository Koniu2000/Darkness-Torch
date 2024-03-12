// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "MainCharAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DARKNESSTORCH_API UMainCharAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AMainCharacter* MainCharacter;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* MainCharacterMovement;

	UPROPERTY(BlueprintReadOnly)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly)
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly)
	ECharacterState CharacterState;

	UPROPERTY(BlueprintReadOnly)
	ECharacterPoseState CharacterPoseState;
};
