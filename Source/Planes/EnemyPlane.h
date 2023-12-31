// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyPlane.generated.h"
 
/**
 * 
 */
UCLASS()
class PLANES_API AEnemyPlane : public ABasePawn
{
	GENERATED_BODY()
public:
	AEnemyPlane();
	virtual void Tick(float DeltaTime) override;


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
