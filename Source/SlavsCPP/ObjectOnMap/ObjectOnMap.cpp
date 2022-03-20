// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectOnMap.h"

// Sets default values
AObjectOnMap::AObjectOnMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Info.Name = "AObjectOnMap";
	Info.Level = 0;
}

// Called when the game starts or when spawned
void AObjectOnMap::BeginPlay()
{
	Super::BeginPlay();
	AObjectOnMap::GetInfo();
}

// Called every frame
void AObjectOnMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObjectOnMap::GetInfo()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, FString::Printf(TEXT("Level: %d, Name: %s"), Info.Level, *Info.Name.ToString()));
	}
	UE_LOG(LogTemp, Warning, TEXT("New %s"), *Info.Name.ToString());
}
