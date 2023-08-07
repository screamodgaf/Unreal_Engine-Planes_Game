// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_UnsetBlackboardKeyValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_UnsetBlackboardKeyValue::UBTTask_UnsetBlackboardKeyValue()
{
	NodeName = TEXT("Unset Blackboard Key Value");
}

EBTNodeResult::Type UBTTask_UnsetBlackboardKeyValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	 ;
	 return EBTNodeResult::Succeeded;
}
