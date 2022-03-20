// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ObjectOnMap/ObjectOnMap.h"
#include "../Resource/Resource.h"
#include "ResourcePlace.generated.h"

/**
 * 
 */
UCLASS()
class SLAVSCPP_API AResourcePlace : public AObjectOnMap
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AResourcePlace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		bool IsEngaged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		TArray<AResource*> Resources;

public:

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		AResource* GetResource(int CountRes);

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void SetResource(AResource* Res);
};
