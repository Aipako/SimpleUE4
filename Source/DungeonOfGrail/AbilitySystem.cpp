// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem.h"
#include "Main_Character.h"

// Sets default values for this component's properties
UAbilitySystem::UAbilitySystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	StartupWidget = CreateDefaultSubobject<UUserWidget>(TEXT("AbilitySystem_StartupWidget"));
}


// Called when the game starts
//void UAbilitySystem::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

void UAbilitySystem::Activate(bool fReset)
{
	if (wStartupWidget) // Check if the Asset is assigned in the blueprint.
	{
		auto character = Cast<AMain_Character>(GetOwner());
		check(character);

		auto characterController = Cast<APlayerController>(character->GetController());
		check(characterController);

		// Create the widget and store it.
		StartupWidget = CreateWidget<UUserWidget>(characterController, wStartupWidget);

		if (StartupWidget)
		{
			//let add it to the view port
			StartupWidget->AddToViewport();

			//Show the Cursor.
			characterController->bShowMouseCursor = true;
			
			characterController->SetInputMode(FInputModeUIOnly());
		}
	}
}

int* UAbilitySystem::GetAbilityValueByType(EAbilityType AbilityType)
{
	switch (AbilityType)
	{
	case EAbilityType::VE_Strength:
		return &Strength;
	case EAbilityType::VE_Agility:
		return &Agility;
	case EAbilityType::VE_Intellect:
		return &Intellect;
	case EAbilityType::VE_Charisma:
		return &Charisma;
	default:
		return 0;
	}
}

bool UAbilitySystem::ValidateAbilityIncrease(EAbilityType AbilityType, int AbilityValue)
{
	if (AbilityValue < 20 && FreePoints != 0)
	{
		return true;
	}
	return false;
}

bool UAbilitySystem::ValidateAbilityDecrease(EAbilityType AbilityType, int AbilityValue)
{
	if (AbilityValue > 0)
	{
		return true;
	}
	return false;
}

void UAbilitySystem::CreateRollResultWidget(int diceValue, int penaltyValue, int resultValue, bool result)
{
	if (wRollWidget) // Check if the Asset is assigned in the blueprint.
	{
		auto character = Cast<AMain_Character>(GetOwner());
		check(character);

		auto characterController = Cast<APlayerController>(character->GetController());
		check(characterController);

		// Create the widget and store it.
		RollWidget = Cast<URollWidget>(CreateWidget<UUserWidget>(characterController, wRollWidget));

		if (RollWidget)
		{
			//let add it to the view port
			RollWidget->AddToViewport();

			//Show the Cursor.
			characterController->bShowMouseCursor = true;

			characterController->SetInputMode(FInputModeUIOnly());

			RollWidget->SyncValues(diceValue, penaltyValue, result);
		}
	}
}

bool UAbilitySystem::RollDice(EAbilityType AbilityType)
{
	int abilityValue = *GetAbilityValueByType(AbilityType);
	int diceValue = FMath::RandRange(1, 20);
	int penaltyValue = (abilityValue - 10) / 2;
	int resultValue = diceValue + penaltyValue;
	bool result = resultValue < 10;
	CreateRollResultWidget(diceValue, penaltyValue, resultValue, result);
	return result;
}

bool UAbilitySystem::IncreaseAbility(EAbilityType AbilityType)
{
	auto abilityValue = GetAbilityValueByType(AbilityType);
	if (ValidateAbilityIncrease(AbilityType, *abilityValue))
	{
		FreePoints--;
		(*abilityValue)++;
		return true;
	}
	return false;
}

bool UAbilitySystem::DecreaseAbility(EAbilityType AbilityType)
{
	auto abilityValue = GetAbilityValueByType(AbilityType);
	if (ValidateAbilityDecrease(AbilityType, *abilityValue))
	{
		FreePoints++;
		(*abilityValue)--;
		return true;
	}
	return false;
}
