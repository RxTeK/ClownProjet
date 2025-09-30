// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeClownProject.h"
#include "CharaPlayer.h"

AGameModeClownProject::AGameModeClownProject()
{
	DefaultPawnClass = ACharaPlayer::StaticClass();
}
