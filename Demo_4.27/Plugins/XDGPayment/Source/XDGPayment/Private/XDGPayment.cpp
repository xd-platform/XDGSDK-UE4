// Copyright Epic Games, Inc. All Rights Reserved.

#include "XDGPayment.h"

#define LOCTEXT_NAMESPACE "FXDGPaymentModule"

FXDGPaymentModule::FXDGSDKPaymentSucceed FXDGPaymentModule::OnXDGSDKPaymentSucceed;
FXDGPaymentModule::FXDGSDKPaymentFailed FXDGPaymentModule::OnXDGSDKPaymentFailed;

FXDGPaymentModule::FXDGSDKQueryProductIdsSucceed FXDGPaymentModule::OnXDGSDKQueryProductIdsSucceed;
FXDGPaymentModule::FXDGSDKQueryProductIdsFailed FXDGPaymentModule::OnXDGSDKQueryProductIdsFailed;

//安卓内嵌支付用
FXDGPaymentModule::FXDGSDKQueryInnerProductsSucceed FXDGPaymentModule::OnXDGSDKQueryInnerProductsSucceed;
FXDGPaymentModule::FXDGSDKQueryInnerProductsFailed FXDGPaymentModule::OnXDGSDKQueryInnerProductsFailed;
FXDGPaymentModule::FXDGSDKInlinePayPaymentCompleted FXDGPaymentModule::OnXDGSDKInlinePayPaymentCompleted;

FXDGPaymentModule::FXDGSDKQueryRestoredPurchasesSucceed FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesSucceed;
FXDGPaymentModule::FXDGSDKQueryRestoredPurchasesFailed FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesFailed;

FXDGPaymentModule::FXDGSDKPayWithWebCompleted FXDGPaymentModule::OnXDGSDKPayWithWebCompleted;
FXDGPaymentModule::FXDGSDKCheckRefundStatusSucceed FXDGPaymentModule::OnXDGSDKCheckRefundStatusSucceed;
FXDGPaymentModule::FXDGSDKCheckRefundStatusFailed FXDGPaymentModule::OnXDGSDKCheckRefundStatusFailed;

IMPLEMENT_MODULE(FXDGPaymentModule, XDGPayment)
void FXDGPaymentModule::StartupModule()
{

}

void FXDGPaymentModule::ShutdownModule()
{

}
#undef LOCTEXT_NAMESPACE
	
