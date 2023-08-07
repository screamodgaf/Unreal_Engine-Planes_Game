// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "TimerManager.h"
#include "HeroPlanePawn.h"
#include "Kismet/GameplayStatics.h"
#include "MyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
 
AEnemyCharacter::AEnemyCharacter() :
	fireFrequency(1.5f)
{
	PrimaryActorTick.bCanEverTick = true;
	//GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	//GetCharacterMovement()->BrakingDecelerationFlying = 100.f;
	//GetCharacterMovement()
	GetCharacterMovement()->bCheatFlying = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
 
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto vec = GetCharacterMovement()->Velocity;
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, 
	//	FString::Printf(TEXT("PensdingVector: %s"), *vec.ToString()));
	 
	 
	 

 

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

void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT(" AEnemyCharacter::SetupPlayerInputComponent")));
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	heroPlane = Cast<AHeroPlanePawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(fireTimerHandle, this, &AEnemyCharacter::checkIfInRangeAndFire, fireFrequency, true);
	//if(IsPlayerControlled())
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("IsPlayerControlled ") ));
	//else
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Is NOT PlayerControlled ")));
 //
}

void AEnemyCharacter::checkIfInRangeAndFire()
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
