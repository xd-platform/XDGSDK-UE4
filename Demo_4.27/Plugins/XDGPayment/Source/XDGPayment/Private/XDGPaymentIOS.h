// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#pragma once

#include "CoreMinimal.h"
#include "XDGPaymentBridge.h"

#import <Foundation/Foundation.h>
#import <XDGPaymentSDK/XDGOrderInfo.h>
#import <XDGPaymentSDK/XDGTransactionInfo.h>
#import <XDGPaymentSDK/XDGPayment.h>
#import <XDGPaymentSDK/XDGProductInfo.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>

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
					FString roleId,
					FString productId, 
					FString extras);

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


@interface XDGUE4PaymentTool : NSObject

+(NSArray*)getProductIdList:(NSString*)listJson;

+ (void)bridgePayCallback:(XDGOrderInfo *)orderInfo error:(NSError *)error;

+ (void)bridgeRefundStatusWithCode:(XDGRepayMentCode)code msg:(NSString *)msg data:(NSDictionary *)data;

+ (NSString *)randomStr;

@end


#endif