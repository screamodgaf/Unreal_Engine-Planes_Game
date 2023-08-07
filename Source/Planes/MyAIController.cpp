// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Math/UnrealMathVectorCommon.h"
#include "Math/UnrealMathUtility.h"
#include "BehaviorTree/Tasks/BTTask_MoveDirectlyToward.h"
#include "BehaviorTree/BehaviorTree.h"

AMyAIController::AMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	 
 
}

void AMyAIController::Tick(float DeltaTime)
{
	//APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
 
	//////if (behaviorTree)
	//////{
	//////	//RunBehaviorTree(behaviorTree);
	//////	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//////	if (LineOfSightTo(playerPawn))
	//////	{
	//////		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
	//////		GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), playerPawn->GetActorLocation());
	//////	}
	//////	else
	//////	{
	//////		GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//////	}
	//////}

	//behaviorTree->AddToRoot();
	//behaviorTree.movedivec
	//if (playerPawn && owningCharacter)
	//{
	//	//float dist = FVector::Distance(GetCharacter()->GetActorLocation(), playerPawn->GetActorLocation());
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("dist %d"), dist));
	//    float dist = owningCharacter->GetDistanceTo(playerPawn); 
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("dist %f"), dist));
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("owningCharacter Location %s"), *GetCharacter()->GetActorLocation().ToString()));

	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("owningCharacter Location %s"), *playerPawn->GetActorLocation().ToString()));
	// 

	//	auto movement = owningCharacter->GetCharacterMovement();
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Speed %d"), dist));

	//	//float maxSpeed = 5400.f;
	//	//float newSpeed = 0;
	//	//if (dist < 7500.f)
	//	//	maxSpeed -= 0.01;
	//	// 
	//	movement->MaxWalkSpeed = 5400;

	// 
	//	
	//	//MoveToActor(playerPawn, 3500.f, true, true, false);
	//	 
	//	 
	//	/*FMath::FInterpTo();*/
	//	//if(dist < 1000) v -= 1;  if (distance > 1000) v += przyspieszenie;  clamp(v, 0, v_max)
	//}

	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("newSpeed %f"), newSpeed));
	//	 
	//	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("speed: %f"), movement->MaxWalkSpeed));
	//	//movement->MaxWalkSpeed = newSpeed;
	//	 
	 
}

 
 
	 

 

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
 
void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

 

	if (behaviorTree)
	{
		RunBehaviorTree(behaviorTree);
		/*APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (playerPawn)
		{
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		}*/
	}

	////MoveToLocation({1000,1000,1000});
	//if (playerPawn) 
	//{
	//	SetFocus(playerPawn);
	//	MoveToActor(playerPawn, 500.f);
	//}
	//else
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("playerPawn = nullptr")));

	//if (behaviorTree)
	//{
	//	RunBehaviorTree(behaviorTree);
	//	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//	if(playerPawn)
	//	{  
	//		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
	//		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	//	}
	//}




	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto owningCharacter = GetCharacter();


	if (behaviorTree)
	{
		//RunBehaviorTree(behaviorTree);
		//APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (LineOfSightTo(playerPawn)) {
			if (playerPawn)
			{
				GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
				GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
			}
		}
	}
	//MoveToActor(playerPawn, 3500.f, false, true, false);


}



void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	 

	//APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT(" AMyAIController::OnMoveCompleted"), *FPathFollowingResult.));

}
