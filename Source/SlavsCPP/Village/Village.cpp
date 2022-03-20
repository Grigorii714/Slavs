// Fill out your copyright notice in the Description page of Project Settings.


#include "Village.h"

// Sets default values
AVillage::AVillage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVillage::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Village"));
}

// Called every frame
void AVillage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVillage::AddBuilding(ABuilding* Building)
{
}

void AVillage::AddResident(ACreature* Creature)
{
}

ACreature* AVillage::GetFreeResident(ABuilding* Building)
{
	return nullptr;
}

