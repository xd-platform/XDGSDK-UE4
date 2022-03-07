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
    FXDGAccountModule::OnXDGSDKLoginSync.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSync);

    //XDGPayment
    FXDGPaymentModule::OnXDGSDKPaymentSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentSucceed);
    FXDGPaymentModule::OnXDGSDKPaymentFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentFailed);
    
    FXDGPaymentModule::OnXDGSDKQueryProductIdsSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsSucceed);
    FXDGPaymentModule::OnXDGSDKQueryProductIdsFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsFailed);

    FXDGPaymentModule::OnXDGSDKQueryInnerProductsSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryInnerProductsSucceed);
    FXDGPaymentModule::OnXDGSDKQueryInnerProductsFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryInnerProductsFailed);
    FXDGPaymentModule::OnXDGSDKInlinePayPaymentCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInlinePayPaymentCompleted);

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
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKLoginFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKLoginFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKLoginFailed: " + msg);
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


//XDGPayment
void ADemoGameModeBase::OnXDGSDKPaymentSucceed(const FString& orderId, const FString& productId, const FString& serverId, const FString& roleId){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPaymentSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPaymentSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKPaymentFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPaymentFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPaymentFailed: ");
}

void ADemoGameModeBase::OnXDGSDKQueryProductIdsSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryProductIdsSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryProductIdsSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKQueryProductIdsFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryProductIdsFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryProductIdsFailed: ");
}

void ADemoGameModeBase::OnXDGSDKQueryInnerProductsSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryInnerProductsSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryInnerProductsSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKQueryInnerProductsFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryInnerProductsFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryInnerProductsFailed: ");
}

void ADemoGameModeBase::OnXDGSDKInlinePayPaymentCompleted(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKInlinePayPaymentCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInlinePayPaymentCompleted: " + resultJson);
}

void ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryRestoredPurchasesSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryRestoredPurchasesSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKQueryRestoredPurchasesFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKQueryRestoredPurchasesFailed: ");
}

void ADemoGameModeBase::OnXDGSDKPayWithWebCompleted(const FString& serverId, const FString& roleId, const int32 code,  const FString& errorMsg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKPayWithWebCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKPayWithWebCompleted: ");
}

void ADemoGameModeBase::OnXDGSDKCheckRefundStatusSucceed(const FString& resultJson){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKCheckRefundStatusSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKCheckRefundStatusSucceed: ");
}

void ADemoGameModeBase::OnXDGSDKCheckRefundStatusFailed(const int32 code, const FString& msg){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKCheckRefundStatusFailed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKCheckRefundStatusFailed: ");
}

