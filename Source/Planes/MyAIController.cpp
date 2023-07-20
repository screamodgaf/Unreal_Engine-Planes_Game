// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Kismet/GameplayStatics.h"

 
AMyAIController::AMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyAIController::Tick(float DeltaTime)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Tick")));
	Super::Tick(DeltaTime);
	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//MoveToLocation({ 1000,1000,1000 });
	if (playerPawn) 
	{
		SetFocus(playerPawn);
		
		//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Tick")), playerPawn->GetController() );
		 
		//MoveToLocation({ -4960, 10120, 200 });
		MoveToActor(playerPawn, 100.f);
		 
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("playerPawn = nullptr")));
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//MoveToLocation({1000,1000,1000});
	if (playerPawn) 
	{
		SetFocus(playerPawn);
		MoveToActor(playerPawn, 500.f);
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("playerPawn = nullptr")));

 
}
