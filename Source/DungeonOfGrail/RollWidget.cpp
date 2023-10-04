// Fill out your copyright notice in the Description page of Project Settings.


#include "RollWidget.h"

void URollWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

	DiceRollResult = 0;
	AbilityPenaltyResult = 0;
	bIsPassed = 0;
}

void URollWidget::SyncValues(int rollResult, int penaltyResult, bool isPassed)
{
	DiceRollResult = rollResult;
	AbilityPenaltyResult = penaltyResult;
	bIsPassed = isPassed;
}
