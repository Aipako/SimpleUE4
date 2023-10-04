// Fill out your copyright notice in the Description page of Project Settings.


#include "StartupWidget.h"

void UStartupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

	//StrengthIncreaseButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("MyButtonName")); // The second parameter is the name and is optional.
	//StrengthIncreaseButton->OnClicked.AddDynamic(this, &UStartupWidget::OnStrengthIncreaseButtonClicked); // Example click binding.
	//RootWidget->AddChild(StrengthIncreaseButton);


}

//void UStartupWidget::OnStrengthIncreaseButtonClicked()
//{
//
//}