// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANES_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	void moveForward(float value);
	void moveSideways(float value);

	//void shootGun();
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float turnRate = 45.f;

	//UPROPERTY(EditAnywhere, Category = "Movement")
	//	class UCharacterMovementComponent* movementComponent;
};
