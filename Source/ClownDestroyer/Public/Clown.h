// EnemyAI.h
#pragma once

#include "CoreMinimal.h"
#include "ParentAI.h"
#include "GameFramework/Character.h"
#include "Clown.generated.h"

UCLASS()
class CLOWNDESTROYER_API AClown : public AParentAI
{
	GENERATED_BODY()

public:
	AClown();

protected:
	virtual void BeginPlay() override;
	

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float FollowDistance = 500000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float AttackRange = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float AttackCooldown = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float MoveSpeed = 300.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI")
	bool bCanAttack = true;

	UPROPERTY()
	APawn* PlayerPawn;

	FTimerHandle AttackCooldownTimer;

	void AttackPlayer();
	void ResetAttack();
};
