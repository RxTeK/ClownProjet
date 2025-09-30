// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class CLOWNDESTROYER_API UBTTask_FindRandomLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	
	UBTTask_FindRandomLocation();

protected:
	UPROPERTY(EditAnywhere, Category = "Search")
	float SearchRadius = 1000.f;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
