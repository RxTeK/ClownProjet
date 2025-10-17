// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharaPlayer.h"
#include "PaperZDCharacter.h"
#include "GameFramework/Character.h"
#include "ParentAI.generated.h"

UCLASS()
class CLOWNDESTROYER_API AParentAI : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParentAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int PV = 3;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Stress = 0.f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void SetPV(int Damage);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	ACharaPlayer* Characte;
	
};
