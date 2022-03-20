// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Building/Building.h"
#include "../Resource/Resource.h"
#include "ResourceFactory.generated.h"

/**
 * 
 */
UCLASS()
class SLAVSCPP_API AResourceFactory : public ABuilding
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AResourceFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		TArray<AResource*> Resources;

public:

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void ExportRequest();

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void CreateResource();

};
