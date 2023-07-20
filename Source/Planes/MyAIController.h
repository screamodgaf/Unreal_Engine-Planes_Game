// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class PLANES_API AMyAIController : public AAIController
{
	GENERATED_BODY()
 
public:
	AMyAIController();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay();

private:
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* behaviorTree;
};
 