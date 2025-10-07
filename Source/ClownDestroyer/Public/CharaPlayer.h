// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharaPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UShootComponent;
class UInputMappingContext;
struct FInputActionValue;


UCLASS()
class CLOWNDESTROYER_API ACharaPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharaPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ShootAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RotateAction;

	

 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	void Rotation(const FInputActionValue& Value);
	
	void ShootFinish();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Component)
	UShootComponent* ShootComponentRef;

	/** Called for looking input */
	void Shoot();
	
	UPROPERTY()
	FVector2D MovementVector;

	UPROPERTY()
	FVector2D RotationVector;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;
};
