// Fill out your copyright notice in the Description page of Project Settings.


#include "Torch.h"
#include "Components/PointLightComponent.h"
#include "Components/CapsuleComponent.h"
#include "MainCharacter.h"

// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TorchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorchMesh"));
	TorchMesh->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
	RootComponent = TorchMesh;

	TorchCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TorchCapsule"));
	TorchCapsule->SetupAttachment(TorchMesh);

	TorchLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("TorchLight"));
	TorchLight->SetupAttachment(TorchMesh);
}

// Called when the game starts or when spawned
void ATorch::BeginPlay()
{
	Super::BeginPlay();
	
	TorchCapsule->OnComponentBeginOverlap.AddDynamic(this, &ATorch::OnCapsuleOverlap);
	TorchCapsule->OnComponentEndOverlap.AddDynamic(this, &ATorch::OnCapsuleEndOverlap);
}

void ATorch::OnCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
	if (MainCharacter)
	{
		MainCharacter->SetOverlappingTorch(this);
	}
}

void ATorch::OnCapsuleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
	if (MainCharacter)
	{
		MainCharacter->SetOverlappingTorch(nullptr);
	}
}

// Called every frame
void ATorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATorch::Equip(USceneComponent* InParent, FName InSocketName)
{
	FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	TorchMesh->AttachToComponent(InParent, TransformRules, FName("LeftHandSocket"));
	TorchMesh->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
}

