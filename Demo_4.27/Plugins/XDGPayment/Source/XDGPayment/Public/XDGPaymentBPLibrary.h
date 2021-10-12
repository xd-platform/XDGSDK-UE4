// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XDGPaymentBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDGPAYMENT_API UXDGPaymentBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	//ios 安卓都有的方法
	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void QueryWithProductIdArray(TArray<FString> productIds);

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext);

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void QueryRestoredPurchases();

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void CheckRefundStatus();

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void CheckRefundStatusWithUI();

	//安卓独有方法
	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void RestorePurchase(FString purchaseToken,
								FString productId,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext);

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void PayWithWeb(FString serverId,
							FString roleId);

	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void PayWithChannel(FString orderId,
								FString productId,
								FString roleId,
								FString serverId,
								FString ext);
    
	//iOS独有方法
	UFUNCTION(BlueprintCallable, Category = "XDGPayment")
	static void PurchaseToken(FString transactionIdentifier,
								FString productIdentifier,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext);
	
};
