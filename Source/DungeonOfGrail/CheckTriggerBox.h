// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Main_Character.h"
#include "AbilitySystem.h"
#include "CheckTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONOFGRAIL_API ACheckTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;

public:

	ACheckTriggerBox();

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Ability)
	EAbilityType AbilityType;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);


	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);


};
