// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentAI.h"
#include "CharaPlayer.h"
#include "HealthWidget.h"
#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AParentAI::AParentAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AParentAI::BeginPlay()
{
	Super::BeginPlay();
	Characte = Cast<ACharaPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
}

// Called every frame
void AParentAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Characte != nullptr)
	{
		FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(GetSprite()->GetComponentLocation(),Characte->CameraComponent->GetComponentLocation());
		GetSprite()->SetWorldRotation(FRotator(0, Rotator.Yaw - 90, Rotator.Roll - 45));
	}
	

}

// Called to bind functionality to input
void AParentAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AParentAI::SetPV(int Damage)
{
	PV = PV - Damage;
	if (PV <= 0)
	{
		ACharaPlayer* Character = Cast<ACharaPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
		if (Character)
		{
			Character->SetStress(Stress);
          
			if (Character->HealthWidgetInstance)
			{
				Character->HealthWidgetInstance->AddScore(1); // +1 à chaque kill
			}
          
			K2_DestroyActor();
		}
	}
}



