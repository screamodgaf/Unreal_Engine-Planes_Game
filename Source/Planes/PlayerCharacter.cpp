// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter() :
	speed(200.f)
{
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
	camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

	//movementComponent = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("CharacterMovementComponent"));
}
 


void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	velocity += acceleration * speed * UGameplayStatics::GetWorldDeltaSeconds(this);;
	velocity = velocity.GetClampedToMaxSize(175.f);
	if (velocity.X <= 0) velocity.X = 0; //so to plane doesnt go backward (below velocity =0) when S pressed
	//if (velocity.X > GetCharacterMovement()->MaxWalkSpeed) velocity.X = GetCharacterMovement()->MaxWalkSpeed;
		 
		 
	AddActorLocalOffset(velocity, true);

 

	//acceleration = FVector::ZeroVector;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	 
	PlayerInputComponent->BindAxis(TEXT("ForwardTrust"), this, &APlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::moveSideways);

	PlayerInputComponent->BindAction(TEXT("ShootGun"), IE_Pressed, this, &APlayerCharacter::shootGun);

}



void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();


}

//void AHeroPlanePawn::onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("AHeroPlanePawn on hit"));
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Hit")));
//}

void APlayerCharacter::moveForward(float value)
{
	acceleration.X = value;
	//if (Controller != nullptr && value != 0) {
	//	const FRotator rotation = Controller->GetControlRotation();
	//	const FRotator yawRotation = { 0, rotation.Yaw, 0 };
	//	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	//	AddMovementInput(direction, value);

	//}
}

void APlayerCharacter::moveSideways(float value)
{
	if (Controller != nullptr && value != 0) {
		//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("value %f"), value));
		FRotator deltaRotation = FRotator::ZeroRotator;
		deltaRotation.Yaw = value * turnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
		AddActorLocalRotation(deltaRotation, true);
	 
	}
	//if (Controller != nullptr && value != 0) {
	//	const FRotator rotation = Controller->GetControlRotation(); 
	//	const FRotator yawRotation = { 0, rotation.Yaw, 0 };
	//	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	//	AddMovementInput(direction, value);
	 
	//}   
 
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
