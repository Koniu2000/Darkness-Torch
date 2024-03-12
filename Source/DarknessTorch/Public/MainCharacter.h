// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "MainCharacter.generated.h"

UCLASS()
class DARKNESSTORCH_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;
	void Crouch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Equip();

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	ECharacterPoseState CharacterPoseState = ECharacterPoseState::ECPS_Stand;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* EquipAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
	class ATorch* OverlappingTorch;

public:
	FORCEINLINE void SetOverlappingTorch(ATorch* Torch) { OverlappingTorch = Torch; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE ECharacterPoseState GetCharacterPoseState() const { return CharacterPoseState; }
};
