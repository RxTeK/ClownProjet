// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "GameFramework/Character.h"
#include "HealthWidget.h" 
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "CharaPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UShootComponent;
class UInputMappingContext;
struct FInputActionValue;


UCLASS()
class CLOWNDESTROYER_API ACharaPlayer : public APaperZDCharacter
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Component)
	UShootComponent* ShootComponentRef;

 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	void Rotation(const FInputActionValue& Value);



	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UArrowComponent* ArrowPlayer;

	UPROPERTY()
	FVector2D MovementVector;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector2D RotationVector;

	int PV = 3;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UHealthWidget> HealthWidgetClass;

	UFUNCTION()
	void SetStress(float StressAdd);

	private:
	UHealthWidget* HealthWidgetInstance;

	UPROPERTY()
	float Stress;
	 
};
