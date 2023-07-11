// Fill out your copyright notice in the Description page of Project Settings.


#include "GunProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AGunProjectile::AGunProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	gunProjectileMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Projectile Mesh"));
	RootComponent = gunProjectileMesh;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	projectileMovementComponent->MaxSpeed = 6500.f;
	projectileMovementComponent->InitialSpeed = 20000.f;
}

// Called when the game starts or when spawned
void AGunProjectile::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("AGunProjectile::BeginPlay()"));
	gunProjectileMesh->OnComponentHit.AddDynamic(this, &AGunProjectile::onHit);
}

// Called every frame
void AGunProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunProjectile::onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("AGunProjectile on hit"));
}

