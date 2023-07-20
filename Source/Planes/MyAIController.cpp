// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
 
AMyAIController::AMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyAIController::Tick(float DeltaTime)
{
/* 
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Tick")));
	Super::Tick(DeltaTime);
	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (playerPawn) 
	{
		SetFocus(playerPawn);
		//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Tick")), playerPawn->GetController() );
		MoveToActor(playerPawn, 100.f); 
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("playerPawn = nullptr")));
*/
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	 
	////MoveToLocation({1000,1000,1000});
	//if (playerPawn) 
	//{
	//	SetFocus(playerPawn);
	//	MoveToActor(playerPawn, 500.f);
	//}
	//else
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("playerPawn = nullptr")));

	if (behaviorTree)
	{
		RunBehaviorTree(behaviorTree);
		APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if(playerPawn)
		{  
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		}
	}
}
