// Fill out your copyright notice in the Description page of Project Settings.


#include "Creature.h"

#include "../Resource/Resource.h"
#include "../ObjectOnMap/ObjectOnMap.h"
//#include "../AIC_Creature/AIC_Creature.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
ACreature::ACreature()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Characteristic.Name = "ACreature";

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Trigger"));
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACreature::OnOverlapBegin);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
}


// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("New %s"), *Characteristic.Name.ToString()); 
}

// Called every frame
void ACreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACreature::TakeToBackpack(AResource* Resourse)
{
	UE_LOG(LogTemp, Warning, TEXT("TakeToBackpack"));
	Resourse->Hide();
	this->Backpack.Add(Resourse);
	GetBackpackInfo();
}

void ACreature::GetBackpackInfo()
{
	for (int i = 0; i < Backpack.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Res %s"), *Backpack[i]->Name.ToString());
		UE_LOG(LogTemp, Warning, TEXT("%d"), Backpack[i]->Count);
	}
}

void ACreature::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AResource::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Res!!!!!!!!"));
		AResource* Res = Cast<AResource>(OtherActor);
		TakeToBackpack(Res);
		
	}     
	/*
	AAIC_Creature* CurrentController = Cast<AAIC_Creature>(GetController());
	TargetPoint = CurrentController->GetNextPoint();
	if (OtherActor == NextPoint)
	{
		for (int i = 0; i < TargetPoints.Num(); i++)
			if (TargetPoints[i] == NextPoint)
			{
				int k = 0;
				while (TargetPoints[(i + 1 + k) % TargetPoints.Num()]->IsActorBeingDestroyed() && k < TargetPoints.Num())
				{
					k++;
					UE_LOG(LogTemp, Warning, TEXT("Miss %d"), k);
				}
				NextPoint = TargetPoints[(i + 1 + k) % TargetPoints.Num()];
				UE_LOG(LogTemp, Warning, TEXT("Next point %d"), i+1);
				break;
			}
	}
	*/
}