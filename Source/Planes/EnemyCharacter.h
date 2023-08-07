// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANES_API AEnemyCharacter : public APlayerCharacter
{
	GENERATED_BODY()
public:
	AEnemyCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay();

private:
	class AHeroPlanePawn* heroPlane;

	FTimerHandle fireTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Weapons")
		float fireRange = 10000.f;

	UPROPERTY(EditAnywhere, Category = "Weapons")
		float fireFrequency;

	 

private:
	void checkIfInRangeAndFire();

};
