// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectOnMap.generated.h"

USTRUCT(BlueprintType)
struct FObjectInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Level;
};

UCLASS()
class SLAVSCPP_API AObjectOnMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObjectOnMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		FObjectInfo Info;

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void GetInfo();

};