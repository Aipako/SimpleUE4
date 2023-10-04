// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckTriggerBox.h"

ACheckTriggerBox::ACheckTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ACheckTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACheckTriggerBox::OnOverlapEnd);
}

void ACheckTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void ACheckTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) 
	{
		AMain_Character* character = Cast<AMain_Character>(OtherActor);
		if (character)
		{
			character->AbilitySys->RollDice(this->AbilityType);
		}
	}
}

void ACheckTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{

}
