// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "GunProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
//#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Casule Collider"));

	capsuleComponent->SetCapsuleSize(200, 200, true);
	//capsuleComponent->SetSimulatePhysics(true);
	RootComponent = capsuleComponent;
	 
	//pawnMovementComponent = CreateDefaultSubobject<UPawnMovementComponent>(TEXT("Pawn Movement Component"));
	floatingPawnMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement Component"));

	/*hitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	hitBox->SetSimulatePhysics(true);
	hitBox->SetupAttachment(capsuleComponent);*/



	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Base Mesh"));
	skeletalMesh->SetSimulatePhysics(true);
	skeletalMesh->SetNotifyRigidBodyCollision(true);
	skeletalMesh->SetupAttachment(capsuleComponent);
	skeletalMesh->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	/*skeletalMesh->OnComponentHit.AddDynamic(this, &ABasePawn::onComponentHit);*/



	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Sprawn Point"));
	projectileSpawnPoint->SetupAttachment(skeletalMesh);

	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();

	skeletalMesh->OnComponentHit.AddDynamic(this, &ABasePawn::onComponentHit);
 
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn::Tick"));

 
}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::performDestruction()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT(" ABasePawn::performDestruction() ") ));
	if (deathParticles)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, FString::Printf(TEXT(" ABasePawn::performDestruction() EXPLOSION")));
		UGameplayStatics::SpawnEmitterAtLocation(this, deathParticles, GetActorLocation(), GetActorRotation());
	}

	Destroy();
}

void ABasePawn::shootGun()
{
	UE_LOG(LogTemp, Warning, TEXT("ABasePawn::shootGun()") );
	if (projectileSpawnPoint == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("ABasePawn projectileSpawnPoint == nullptr"));
		return;
	}

	FVector location = projectileSpawnPoint->GetComponentLocation(); //location of the bullet
	FRotator rotation = projectileSpawnPoint->GetComponentRotation();

	auto projectile = GetWorld()->SpawnActor<AGunProjectile>(projectileClass, location, rotation);
	projectile->SetOwner(this);
}

void ABasePawn::onComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn on hit %s"), *OtherActor->GetActorLocation().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn HIT"));
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Hit")));
	
 
}

