// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPlane.h"
#include "TimerManager.h"
#include "HeroPlanePawn.h"
#include "Kismet/GameplayStatics.h"
#include "MyAIController.h"
 

AEnemyPlane::AEnemyPlane():
	fireFrequency(1.5f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	//auto AIController = Cast<AMyAIController>(GetController());
	//if (AIController)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("IsPlayerControlled ")));
		//APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//	AIController->MoveToLocation({ 100, 1000, 1000 });
 //
	//}


	//AController* myEnemyController =  GetController();
	//AAIController* myAIEnemyController = Cast<AAIController>(myEnemyController);
	//
	//auto heroPlane2 = Cast<AHeroPlanePawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	//myAIEnemyController->MoveToActor(heroPlane2);

	//if (IsBotControlled())
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Purple, FString::Printf(TEXT("I AM BOT CONTROLLED")));
	//}else
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Purple, FString::Printf(TEXT("I AM NOOOOT!! BOT CONTROLLED")));
	// 
	//if (myAIEnemyController)
	//{
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("I AM CONTROLLED BY AI ")));
	//	//whatever other logic you need

	 
	//}
}

void AEnemyPlane::BeginPlay()
{
	Super::BeginPlay();
	
	heroPlane = Cast<AHeroPlanePawn>(UGameplayStatics::GetPlayerPawn(this, 0));
 
	GetWorldTimerManager().SetTimer(fireTimerHandle, this, &AEnemyPlane::checkIfInRangeAndFire, fireFrequency, true);
	//if(IsPlayerControlled())
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("IsPlayerControlled ") ));
	//else
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Is NOT PlayerControlled ")));
 //
}

void AEnemyPlane::checkIfInRangeAndFire()
{
	if (heroPlane)
	{
		 
		float distanceFromHero = FVector::Dist(GetActorLocation(), heroPlane->GetActorLocation());
		
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("distanceFromHero %f"), distanceFromHero));

		if (distanceFromHero <= fireRange)
		{
			shootGun();
		}

	}
	 
}
