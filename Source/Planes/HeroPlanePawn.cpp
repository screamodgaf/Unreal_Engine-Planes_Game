// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroPlanePawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
 


AHeroPlanePawn::AHeroPlanePawn() :
	speed(200.f),
	turnRate(75.f)
{
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
	camera->bUsePawnControlRotation = false;

	 
} 

void AHeroPlanePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GetCharacterMovement()->AddForce({100000,100000,110000});
	//UE_LOG(LogTemp, Warning, TEXT("GetActorLocation(): %s"), *GetCharacterMovement()->GetActorLocation().ToString());
	/*UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *GetActorRotation().ToString());*/
 
	velocity += acceleration * speed * UGameplayStatics::GetWorldDeltaSeconds(this);;
	velocity = velocity.GetClampedToMaxSize(175.f);
	if (velocity.X < 0) velocity.X = 0; //so to plane doesnt go backward (below velocity =0) when S pressed
 
	AddActorLocalOffset(velocity, true);
 
	//UE_LOG(LogTemp, Warning, TEXT("velocity: %f"), velocity.X);
	//UE_LOG(LogTemp, Warning, TEXT("GetActorLocation(): %s"), *GetCharacterMovement()->GetActorLocation().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *GetActorRotation().ToString());

	//UE_LOG(LogTemp, Warning, TEXT("rotation: %s"), *GetActorRotation().ToString());

	acceleration = FVector::ZeroVector;
}

void AHeroPlanePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("ForwardTrust"), this, &AHeroPlanePawn::moveForward);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AHeroPlanePawn::moveSideways);

	PlayerInputComponent->BindAction(TEXT("ShootGun"), IE_Pressed, this, &AHeroPlanePawn::shootGun);
	 
}

 

void AHeroPlanePawn::BeginPlay()
{
	Super::BeginPlay();
	 
 
}

//void AHeroPlanePawn::onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("AHeroPlanePawn on hit"));
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Hit")));
//}

void AHeroPlanePawn::moveForward(float value)
{
	acceleration.X = value;
	//UE_LOG(LogTemp, Warning, TEXT("moveForward(float value): %f"), value);
	//if (Controller != nullptr && trustAcceleration != 0) {
	//	FVector deltaLocation = FVector::ZeroVector;
	//	deltaLocation.X = trustAcceleration * speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	//	AddActorLocalOffset(deltaLocation, true);
	//	
	//}

	//FRotator rotation = Controller->GetControlRotation();
	//FRotator yawRotation(0.f, rotation.Yaw, 0.f);

	//FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	//AddMovementInput(direction, true);
}

void AHeroPlanePawn::moveSideways(float value)
{
	if (Controller != nullptr && value != 0) {
		FRotator deltaRotation = FRotator::ZeroRotator;
		deltaRotation.Yaw = value * turnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(deltaRotation, true);
	}

	//FRotator rotation = Controller->GetControlRotation();
	//FRotator yawRotation(0.f, rotation.Yaw, 0.f);

	//FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	//AddMovementInput(direction, true);
}

//void AHeroPlanePawn::shootGun()
//{
//	FVector projectileSpawnPointLocation = projectileSpawnPoint->GetComponentLocation();
//	DrawDebugSphere(
//		GetWorld(),
//		projectileSpawnPointLocation,
//		25.f,
//		12,
//		FColor::Red,
//		false,
//		3.f
//	);
//}
