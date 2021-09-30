// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoGameModeBase.h"
#include "XDGCommonModule.h"
#include "Engine.h"

void ADemoGameModeBase::BeginPlay(){
    XDGCommonModule::OnXDGSDKInitSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInitSucceed);
    XDGCommonModule::OnXDGSDKShareSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKShareSucceed);
}


void ADemoGameModeBase::OnXDGSDKInitSucceed(){
    UE_LOG(LogTemp, Log, TEXT("123点击了OnXDGSDKInitSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed");
}


void ADemoGameModeBase::OnXDGSDKShareSucceed(const int32 code){
    UE_LOG(LogTemp, Log, TEXT("点击了OnXDGSDKShareSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKShareSucceed");
}
