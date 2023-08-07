// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_UnsetBlackboardKeyValue.generated.h"

/**
 * 
 */
UCLASS()
class PLANES_API UBTTask_UnsetBlackboardKeyValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_UnsetBlackboardKeyValue();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
