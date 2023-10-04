// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "StartupWidget.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONOFGRAIL_API UStartupWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	

public:
	/*UPROPERTY()
	UButton* StrengthIncreaseButton;

	UFUNCTION()
	void OnStrengthIncreaseButtonClicked();*/
};
