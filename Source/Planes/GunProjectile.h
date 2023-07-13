// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunProjectile.generated.h"


UCLASS()
class PLANES_API AGunProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Weapons")
		USkeletalMeshComponent* gunProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
		class UProjectileMovementComponent* projectileMovementComponent;


private:
	UPROPERTY(EditAnywhere)
		float damageAmount = 50.f;

private:
	UFUNCTION()
		void onHit(
			UPrimitiveComponent* HitComponent,    // First parameter.
			AActor* OtherActor,                   // Second, etc.
			UPrimitiveComponent* OtherComp,
			FVector NormalImpulse,
			const FHitResult& Hit
		);
};
