// Copyright Epic Games, Inc. All Rights Reserved.


#include "DungeonOfGrailGameModeBase.h"

ADungeonOfGrailGameModeBase::ADungeonOfGrailGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("BP_MainCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}