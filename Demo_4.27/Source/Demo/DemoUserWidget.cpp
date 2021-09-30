 // Fill out your copyright notice in the Description page of Project Settings.

#include "DemoUserWidget.h"
#include "CoreMinimal.h"
#include "Engine.h"


void UDemoUserWidget::ShowLog(const FString& result){
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *result);
}


