// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSpoted.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocationIfSpoted::UBTService_PlayerLocationIfSpoted()
{
	NodeName = "Update Player Location If Spoted";
}

void UBTService_PlayerLocationIfSpoted::TickNode(UBehaviorTreeComponent& OwnerComp, 
	uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (playerPawn == nullptr)
	{
		return;
	}
	
	if (OwnerComp.GetAIOwner()->LineOfSightTo(playerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),
			playerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
	 
}
