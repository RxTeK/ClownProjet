// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootComponent.h"

#include "CharaPlayer.h"
#include "FPSProjectile.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShootComponent::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ACharaPlayer>(GetOwner());
	
}


// Called every frame
void UShootComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UShootComponent::ShootBeginEnter()
{
	if (TimerHandle.IsValid() == false)
	{
		GetOwner()->GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UShootComponent::ShootRate, 0.5f, false);
	}
}

void UShootComponent::ShootStart()
{
	// Exemple dans une fonction de votre personnage ou autre acteur
	FVector SpawnLocation = Character->GetActorLocation() + Character->GetActorForwardVector() * 100.0f;
	FRotator SpawnRotation = Character->ArrowPlayer->GetComponentRotation();

	AFPSProjectile* Projectile = GetWorld()->SpawnActor<AFPSProjectile>(
		ProjectilShoot,
		SpawnLocation,
		SpawnRotation
	);

	if (Projectile)
	{
		Projectile->FireInDirection(Character->ArrowPlayer->GetForwardVector());
	}
}

void UShootComponent::ShootRate()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle);
}

