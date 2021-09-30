// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoGameModeBase.h"
#include "XDGCommon.h"
#include <string.h>

void ADemoGameModeBase::BeginPlay(){
    FXDGCommonModule::OnXDGSDKInitSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInitSucceed);
    FXDGCommonModule::OnXDGSDKShareSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKShareSucceed);
    UE_LOG(LogTemp, Log, TEXT("playingsgm"));
}


void ADemoGameModeBase::OnXDGSDKInitSucceed(const bool success){
    UE_LOG(LogTemp, Log, TEXT("点击了OnXDGSDKInitSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed: " + FString::FromInt(success));
}


void ADemoGameModeBase::OnXDGSDKShareSucceed(const int32 code){
    UE_LOG(LogTemp, Log, TEXT("点击了OnXDGSDKShareSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKShareSucceed: " + FString::FromInt(code));
}
