// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XDGPaymentBridge.h"

/**
 * 
 */
class XDGPAYMENT_API XDGPaymentIOS : public XDGPaymentBridge
{
public:
	XDGPaymentIOS();
	~XDGPaymentIOS();

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
    
	//iOS独有方法
	void PurchaseToken(FString transactionIdentifier,
								FString productIdentifier,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext);
};
