// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "HealthComponent.h"
#include "GunProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
 
 
 
	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Base Mesh"));
	skeletalMesh->SetupAttachment(RootComponent);
	skeletalMesh->SetSimulatePhysics(true);
	skeletalMesh->SetNotifyRigidBodyCollision(true);
	skeletalMesh->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	/*skeletalMesh->OnComponentHit.AddDynamic(this, &ABasePawn::onComponentHit);*/

	 
	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Sprawn Point"));
	projectileSpawnPoint->SetupAttachment(skeletalMesh);

	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	skeletalMesh->OnComponentHit.AddDynamic(this, &ABaseCharacter::onComponentHit);

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn::Tick"));


}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT(" SetupPlayerInputComponent ")));*/
}

void ABaseCharacter::performDestruction()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT(" ABasePawn::performDestruction() ")));
	if (deathParticles)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, FString::Printf(TEXT(" ABaseCharacter::performDestruction() EXPLOSION")));
		UGameplayStatics::SpawnEmitterAtLocation(this, deathParticles, GetActorLocation(), GetActorRotation());
	}

	Destroy();
}

void ABaseCharacter::shootGun()
{
	UE_LOG(LogTemp, Warning, TEXT("ABasePawn::shootGun()"));
	if (projectileSpawnPoint == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("ABasePawn projectileSpawnPoint == nullptr"));
		return;
	}

	FVector location = projectileSpawnPoint->GetComponentLocation(); //location of the bullet
	FRotator rotation = projectileSpawnPoint->GetComponentRotation();

	auto projectile = GetWorld()->SpawnActor<AGunProjectile>(projectileClass, location, rotation);
	projectile->SetOwner(this);
}

void ABaseCharacter::onComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn on hit %s"), *OtherActor->GetActorLocation().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("ABasePawn HIT"));
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Hit")));


}

