// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RollWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONOFGRAIL_API URollWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Roll)
	int DiceRollResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Roll)
	int AbilityPenaltyResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Roll)
	bool bIsPassed;

	UFUNCTION(BlueprintCallable)
	void SyncValues(int rollResult, int penaltyResult, bool isPassed);
};
