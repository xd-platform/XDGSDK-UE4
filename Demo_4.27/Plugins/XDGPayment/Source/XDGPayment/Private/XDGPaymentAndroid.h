// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#pragma once

#include "CoreMinimal.h"
#include "XDGPaymentBridge.h"

#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#include "Runtime/Core/Public/Android/AndroidJava.h"

/**
 * 
 */
class XDGPAYMENT_API XDGPaymentAndroid : public XDGPaymentBridge
{
public:
	XDGPaymentAndroid();
	~XDGPaymentAndroid();

	//ios 安卓都有的方法
	void QueryWithProductIds(FString listJson);

	void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext);

	void QueryRestoredPurchases();

	void CheckRefundStatus();

	void CheckRefundStatusWithUI();

	//安卓独有方法
	void RestorePurchase(FString purchaseToken,
								FString productId,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext);

	void PayWithWeb(FString serverId,
							FString roleId);

	void PayWithChannel(FString orderId,
								FString productId,
								FString roleId,
								FString serverId,
								FString ext);
								
    void QueryInnerProductList(FString listJson); //安卓内嵌支付用

	void InlinePay(FString orderId,  
								FString productId,
								FString productName,
								FString region,
								FString serverId,
								FString roleId,
								FString ext);

    
	//iOS独有方法
	void PurchaseToken(FString transactionIdentifier,
								FString productIdentifier,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext);
};


#endif 