// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "Modules/ModuleManager.h"
#include "CoreUObject.h"
#include "Engine.h"

class XDGPAYMENT_API FXDGPaymentModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

     static inline FXDGPaymentModule& Get(){
        return FModuleManager::LoadModuleChecked<FXDGPaymentModule>( "XDGPayment" );
    }

    static inline bool IsAvailable(){
        return FModuleManager::Get().IsModuleLoaded( "XDGPayment" );
    } 

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKPaymentSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDGSDKPaymentFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKQueryProductIdsSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDGSDKQueryProductIdsFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKQueryRestoredPurchasesSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDGSDKQueryRestoredPurchasesFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKPayWithWebComplete, const FString&);
	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKCheckRefundStatusSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDGSDKCheckRefundStatusFailed, const int32, const FString&);

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKPaymentSucceed OnXDGSDKPaymentSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKPaymentFailed OnXDGSDKPaymentFailed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKQueryProductIdsSucceed OnXDGSDKQueryProductIdsSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKQueryProductIdsFailed OnXDGSDKQueryProductIdsFailed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKQueryRestoredPurchasesSucceed OnXDGSDKQueryRestoredPurchasesSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKQueryRestoredPurchasesFailed OnXDGSDKQueryRestoredPurchasesFailed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKPayWithWebComplete OnXDGSDKPayWithWebComplete;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKCheckRefundStatusSucceed OnXDGSDKCheckRefundStatusSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
    static FXDGSDKCheckRefundStatusFailed OnXDGSDKCheckRefundStatusFailed;

};
