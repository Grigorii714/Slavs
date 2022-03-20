// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

UCLASS()
class SLAVSCPP_API AResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource();
	AResource(int Count);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Count;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UBoxComponent* Collision;

public:

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		int AddRes(AResource* Res);

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		AResource* TakeRes(int CountRes);

	UFUNCTION(BlueprintCallable, Category = "CPPFunction")
		void Hide();
};
