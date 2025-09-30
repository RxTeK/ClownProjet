// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerPNJ.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAIControllerPNJ::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}
