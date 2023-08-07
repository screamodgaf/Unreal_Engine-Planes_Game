// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PLANES_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void performDestruction();

	void shootGun();


protected:
	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//	class UCapsuleComponent* capsuleComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USkeletalMeshComponent* skeletalMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* projectileSpawnPoint;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//	class UPawnMovementComponent* pawnMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UFloatingPawnMovement* floatingPawnMovementComponent;


	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UHealthComponent* healthComponent;


	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		TSubclassOf<class AGunProjectile> projectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		class UParticleSystem* deathParticles;

public:

	UFUNCTION()
		void onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	FVector velocity;
	FVector acceleration;
};
