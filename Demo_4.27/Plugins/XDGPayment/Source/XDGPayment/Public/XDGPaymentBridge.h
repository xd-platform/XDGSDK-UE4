// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDGPAYMENT_API XDGPaymentBridge
{
public:

    //ios 安卓都有的方法
	virtual void QueryWithProductIds(FString listJson) = 0;

	virtual void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext) = 0;

	virtual void QueryRestoredPurchases() = 0;

	virtual void CheckRefundStatus() = 0;

	virtual void CheckRefundStatusWithUI() = 0;

	//安卓独有方法
	virtual void RestorePurchase(FString purchaseToken,
								FString productId,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext) = 0;

	virtual void PayWithWeb(FString serverId,
							FString roleId) = 0;

	virtual void PayWithChannel(FString orderId,
								FString productId,
								FString roleId,
								FString serverId,
								FString ext) = 0;
    
	//iOS独有方法
	virtual void PurchaseToken(FString transactionIdentifier,
								FString productIdentifier,
								FString orderId,
								FString roleId,
								FString serverId,
								FString ext) = 0;

};

XDGPaymentBridge *GetXDGPaymentBridge();