// Fill out your copyright notice in the Description page of Project Settings.


#include "CharaPlayer.h"

// Sets default values
ACharaPlayer::ACharaPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharaPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharaPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharaPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

