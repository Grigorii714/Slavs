// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourcePlace.h"


AResourcePlace::AResourcePlace()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Info.Name = "AResourcePlace";
	Info.Level = 0;
}

// Called when the game starts or when spawned
void AResourcePlace::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AResourcePlace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AResource* AResourcePlace::GetResource(int CountRes)
{
	return nullptr;
}

void AResourcePlace::SetResource(AResource* Res)
{
}
