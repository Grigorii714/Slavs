// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Creature.generated.h"

USTRUCT(BlueprintType)
struct FCreatureCharacteristic
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Armor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		int Health;

};

UCLASS()
class SLAVSCPP_API ACreature : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		FCreatureCharacteristic Characteristic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPPVariables")
		TArray<AResource*> Backpack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPPVariables")
		AActor* TargetPoint;

public:

	UFUNCTION(BlueprintCallable, Category = SomeCategory)
		void TakeToBackpack(AResource* Resourse);

	UFUNCTION(BlueprintCallable, Category = SomeCategory)
		void GetBackpackInfo();

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
