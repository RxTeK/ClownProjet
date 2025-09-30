// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIControllerPNJ.generated.h"

UCLASS()
class CLOWNDESTROYER_API AAIControllerPNJ : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	public:
	UPROPERTY(EditAnywhere, Category= "AI")
	UBehaviorTree* BehaviorTree;
};
