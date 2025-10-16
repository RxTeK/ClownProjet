// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParentAI.generated.h"

UCLASS()
class CLOWNDESTROYER_API AParentAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParentAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int PV = 3;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Stress = 0.f;
};
