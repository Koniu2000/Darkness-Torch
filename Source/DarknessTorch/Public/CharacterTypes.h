#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_TorchEquipped UMETA(DisplayName = "Torch Equipped")
};

UENUM(BlueprintType)
enum class ECharacterPoseState : uint8
{
	ECPS_Stand UMETA(DisplayName = "Stand"),
	ECPS_Crouch UMETA(DisplayName = "Crouch")
};