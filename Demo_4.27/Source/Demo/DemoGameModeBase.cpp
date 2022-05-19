// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoGameModeBase.h"
#include "XDGCommon.h"
#include "XDGAccount.h"
#include "XDGPayment.h"
#include <string.h>

void ADemoGameModeBase::BeginPlay(){
    //XDGCommon
    FXDGCommonModule::OnXDGSDKInitSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInitSucceed);
    FXDGCommonModule::OnXDGSDKShareCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKShareCompleted);
    FXDGCommonModule::OnXDGSDKGetRegionInfoCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetRegionInfoCompleted);

    //XDGAccount
    FXDGAccountModule::OnXDGSDKLoginSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSucceed);
    FXDGAccountModule::OnXDGSDKLoginFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginFailed);
    FXDGAccountModule::OnXDGSDKGetUserSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserSucceed);
    FXDGAccountModule::OnXDGSDKGetUserFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserFailed);
    FXDGAccountModule::OnXDGSDKUserStateChanged.AddUObject(this, &ADemoGameModeBase::OnXDGSDKUserStateChanged);

    //XDGPayment
    FXDGPaymentModule::OnXDGSDKPaymentSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentSucceed);
    FXDGPaymentModule::OnXDGSDKPaymentFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentFailed);
    
    FXDGPaymentModule::OnXDGSDKQueryProductIdsSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsSucceed);
    FXDGPaymentModule::OnXDGSDKQueryProductIdsFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsFailed);

    FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesSucceed);
    FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesFailed);
    FXDGPaymentModule::OnXDGSDKPayWithWebCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPayWithWebCompleted);
    FXDGPaymentModule::OnXDGSDKCheckRefundStatusSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKCheckRefundStatusSucceed);
    FXDGPaymentModule::OnXDGSDKCheckRefundStatusFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKCheckRefundStatusFailed);

    UE_LOG(LogTemp, Log, TEXT("playingsgm"));
}

//XDGCommon
void ADemoGameModeBase::OnXDGSDKInitSucceed(const bool success, const FString& result){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKInitSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed: " + FString::FromInt(success) + result);
}


void ADemoGameModeBase::OnXDGSDKShareCompleted(const int32 code){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKShareCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKShareCompleted: " + FString::FromInt(code));
}

void ADemoGameModeBase::OnXDGSDKGetRegionInfoCompleted(const FString& countryCode, const FString& city, const FString& timeZone, const FString& locationInfoType){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKGetRegionInfoCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKGetRegionInfoCompleted: " + countryCode + city + timeZone + locationInfoType);
}


//XDGAccount
void ADemoGameModeBase::OnXDGSDKLoginSucceed(const FString& userJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginSucceed: " + userJson);
}

void ADemoGameModeBase::OnXDGSDKLoginFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginFailed: " + msg);
}

void ADemoGameModeBase::OnXDGSDKGetUserSucceed(const FString& userJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKGetUserSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKGetUserSucceed: " + userJson);
}

void ADemoGameModeBase::OnXDGSDKGetUserFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKGetUserFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKGetUserFailed: " + msg);
}

void ADemoGameModeBase::OnXDGSDKUserStateChanged(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKUserStateChanged"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKUserStateChanged: " + msg);
}


//XDGPayment
void ADemoGameModeBase::OnXDGSDKPaymentSucceed(const FString& orderId, const FString& productId, const FString& serverId, const FString& roleId){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPaymentSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPaymentSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKPaymentFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPaymentFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPaymentFailed: " + msg);
}

void ADemoGameModeBase::OnXDGSDKQueryProductIdsSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryProductIdsSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryProductIdsSucceed: " + resultJson);
}

void ADemoGameModeBase::OnXDGSDKQueryProductIdsFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryProductIdsFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryProductIdsFailed: " + msg);
}

void ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryRestoredPurchasesSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryRestoredPurchasesSucceed: " + resultJson);
}

void ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryRestoredPurchasesFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryRestoredPurchasesFailed: " + msg);
}

void ADemoGameModeBase::OnXDGSDKPayWithWebCompleted(const FString& serverId, const FString& roleId, const int32 code,  const FString& errorMsg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPayWithWebCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPayWithWebCompleted: ");
}

void ADemoGameModeBase::OnXDGSDKCheckRefundStatusSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKCheckRefundStatusSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKCheckRefundStatusSucceed: " + resultJson);
}

void ADemoGameModeBase::OnXDGSDKCheckRefundStatusFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKCheckRefundStatusFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKCheckRefundStatusFailed: " + msg);
}

