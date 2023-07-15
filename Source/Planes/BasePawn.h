// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class PLANES_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void shootGun();
protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCapsuleComponent* capsuleComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USkeletalMeshComponent* skeletalMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* projectileSpawnPoint;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UPawnMovementComponent* pawnMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		TSubclassOf<class AGunProjectile> projectileClass;

public:

	UFUNCTION()
		void onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	FVector velocity;
	FVector acceleration;
};
