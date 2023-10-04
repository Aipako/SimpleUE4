// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AMain_Character;

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Blueprint/UserWidget.h"
#include "RollWidget.h"
#include "AbilitySystem.generated.h"

class AMain_Character;

UENUM(BlueprintType)
enum class EAbilityType : uint8 
{

	VE_Strength       UMETA(DisplayName = "Strength"),
	VE_Agility        UMETA(DisplayName = "Agility"),
	VE_Intellect      UMETA(DisplayName = "Intellect"),
	VE_Charisma       UMETA(DisplayName = "Charisma"),
};

UCLASS( ClassGroup=(Custom))
class DUNGEONOFGRAIL_API UAbilitySystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitySystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ability)
	int Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ability)
	int Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ability)
	int Intellect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ability)
	int Charisma;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ability)
	int FreePoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<class UUserWidget> wStartupWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<class UUserWidget> wRollWidget;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

	int* GetAbilityValueByType(EAbilityType AbilityType);

	bool ValidateAbilityIncrease(EAbilityType AbilityType, int AbilityValue);

	bool ValidateAbilityDecrease(EAbilityType AbilityType, int AbilityValue);

	void CreateRollResultWidget(int diceValue, int penaltyValue, int resultValue, bool result);

	UUserWidget* StartupWidget;

	URollWidget* RollWidget;

public:
	virtual void Activate(bool fReset) override;

	UFUNCTION(BlueprintCallable)
	bool RollDice(EAbilityType AbilityType);

	UFUNCTION(BlueprintCallable)
	bool IncreaseAbility(EAbilityType AbilityType);

	UFUNCTION(BlueprintCallable)
	bool DecreaseAbility(EAbilityType AbilityType);
		
};
