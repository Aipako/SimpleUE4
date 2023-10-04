// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Main_Character.generated.h"

class UAbilitySystem;

UCLASS()
class DUNGEONOFGRAIL_API AMain_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	UAbilitySystem* AbilitySys;

	UPROPERTY()
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Val);

	void MoveRight(float Val);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
