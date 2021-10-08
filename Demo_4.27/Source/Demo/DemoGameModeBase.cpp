// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoGameModeBase.h"
#include "XDGCommon.h"
#include "XDGAccount.h"
#include <string.h>

void ADemoGameModeBase::BeginPlay(){
    //XDGCommon
    FXDGCommonModule::OnXDGSDKInitSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInitSucceed);
    FXDGCommonModule::OnXDGSDKShareSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKShareSucceed);

    //XDGAccount
    FXDGAccountModule::OnXDGSDKLoginSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSucceed);
    FXDGAccountModule::OnXDGSDKLoginFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginFailed);
    FXDGAccountModule::OnXDGSDKGetUserSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserSucceed);
    FXDGAccountModule::OnXDGSDKGetUserFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserFailed);
    FXDGAccountModule::OnXDGSDKUserStateChanged.AddUObject(this, &ADemoGameModeBase::OnXDGSDKUserStateChanged);
    FXDGAccountModule::OnXDGSDKLoginSync.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSync);
    
    UE_LOG(LogTemp, Log, TEXT("playingsgm"));
}

//XDGCommon
void ADemoGameModeBase::OnXDGSDKInitSucceed(const bool success){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKInitSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed: " + FString::FromInt(success));
}


void ADemoGameModeBase::OnXDGSDKShareSucceed(const int32 code){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKShareSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKShareSucceed: " + FString::FromInt(code));
}


//XDGAccount
void ADemoGameModeBase::OnXDGSDKLoginSucceed(const FString& userJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKLoginFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginFailed: ");
}

void ADemoGameModeBase::OnXDGSDKGetUserSucceed(const FString& userJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKGetUserSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKGetUserSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKGetUserFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKGetUserFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKGetUserFailed: ");
}

void ADemoGameModeBase::OnXDGSDKUserStateChanged(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKUserStateChanged"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKUserStateChanged: ");
}

void ADemoGameModeBase::OnXDGSDKLoginSync(const FString& sessionToken){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginSync"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginSync: ");
}