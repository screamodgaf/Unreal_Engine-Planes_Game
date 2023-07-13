// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPlane.h"
#include "TimerManager.h"
#include "HeroPlanePawn.h"
#include "Kismet/GameplayStatics.h"
AEnemyPlane::AEnemyPlane()
{
	 
}

void AEnemyPlane::BeginPlay()
{
	Super::BeginPlay();
	
	heroPlane = Cast<AHeroPlanePawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(fireTimerHandle, this, &AEnemyPlane::checkIfInRangeAndFire, fireFrequency, true);
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
