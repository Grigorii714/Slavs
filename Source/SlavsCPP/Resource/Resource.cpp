// Fill out your copyright notice in the Description page of Project Settings.


#include "Resource.h"
#include "Components/BoxComponent.h"

// Sets default values
AResource::AResource()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Name = "AResourse";

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Capsule"));
	Collision->InitBoxExtent(FVector(10.f, 10.f, 10.f));
	Collision->SetCollisionProfileName(TEXT("Trigger"));
	Collision->SetupAttachment(RootComponent);


	//Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	//Trigger->SetBoxExtent(FVector(200.f, 200.f, 96.f));
	//Trigger->SetCollisionProfileName(TEXT("Trigger"));
	//Trigger->SetupAttachment(GetRootComponent());
}

AResource::AResource(int Count)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	this->Count = Count;
}

// Called when the game starts or when spawned
void AResource::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("New %s"), *Name.ToString());
}

// Called every frame
void AResource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int AResource::AddRes(AResource* Res)
{
	return 0;
}

AResource* AResource::TakeRes(int CountRes)
{
	return nullptr;
}

void AResource::Hide()
{
	Destroy();
	//Collision->SetCollisionProfileName(TEXT("NoCollision"));
}

