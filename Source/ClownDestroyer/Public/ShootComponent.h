// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSProjectile.h"
#include "Components/ActorComponent.h"
#include "ShootComponent.generated.h"

class ACharaPlayer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLOWNDESTROYER_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShootComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	ACharaPlayer* Character;

	FTimerHandle TimerHandle;

	void ShootStart();
	void ShootRate();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ShootBeginEnter();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<AFPSProjectile> ProjectilShoot;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float SpeedAttack = 1.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float lifeTime = 3;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float ProjectilSpeed = 850 ;
	
	
};
