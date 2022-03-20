// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Building/Building.h"
#include "../Creature/Creature.h"
#include "Village.generated.h"

UCLASS()
class SLAVSCPP_API AVillage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVillage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		TArray<ABuilding*> Buildings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		TArray<ACreature*> Residents;

public:
	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void AddBuilding(ABuilding* Building);

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void AddResident(ACreature* Creature);

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		ACreature* GetFreeResident(ABuilding* Building);
};
