// EnemyAI.cpp
#include "Clown.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharaPlayer.h"

AClown::AClown()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AClown::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AClown::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn) return;

	float Distance = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());
	UE_LOG(LogTemp, Warning, TEXT("tick"));

	if (Distance < FollowDistance)
	{
		AAIController* AICon = Cast<AAIController>(GetController());
		if (AICon)
		{
			AICon->MoveToActor(PlayerPawn, 5.0f);
		}

		if (Distance < AttackRange && bCanAttack)
		{
			AttackPlayer();
		}
	}
}

void AClown::AttackPlayer()
{
	bCanAttack = false;
	
	if (ACharaPlayer* Player = Cast<ACharaPlayer>(PlayerPawn))
	{
		Player->PV -= 1;
		FVector Launch(0.0f, 0.0f, 100.0f);

		Player->LaunchCharacter(Launch,false, false);
		if (Player->PV <= 0)
		{
			FVector LaunchKo(0.0f, 0.0f, 5000.0f);

			Player->LaunchCharacter(LaunchKo,false, false);
		}
	}
	GetWorldTimerManager().SetTimer(AttackCooldownTimer, this, &AClown::ResetAttack, AttackCooldown, false);
}

void AClown::ResetAttack()
{
	bCanAttack = true;
}
