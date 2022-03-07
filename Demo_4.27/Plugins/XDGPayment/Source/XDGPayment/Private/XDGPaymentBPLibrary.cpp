// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGPaymentBPLibrary.h"
#include "XDGPaymentBridge.h"
#include "Engine.h"
#include "TapJson.h"

UXDGPaymentBPLibrary::UXDGPaymentBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}

//ios 安卓都有的方法
void UXDGPaymentBPLibrary::QueryWithProductIdArray(TArray<FString> productIds){
    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonOutString);
    Writer->WriteObjectStart();
    Writer->WriteValue(TEXT("list"), productIds);
    Writer->WriteObjectEnd();
    Writer->Close();

    GetXDGPaymentBridge()->QueryWithProductIds(JsonOutString);    
}

void UXDGPaymentBPLibrary::PayWithProduct(FString orderId,
                                        FString productId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    GetXDGPaymentBridge()->PayWithProduct(orderId, productId, roleId, serverId, ext);
}


void UXDGPaymentBPLibrary::QueryRestoredPurchases(){
    GetXDGPaymentBridge()->QueryRestoredPurchases();
}


void UXDGPaymentBPLibrary::CheckRefundStatus(){
    GetXDGPaymentBridge()->CheckRefundStatus();
}


void UXDGPaymentBPLibrary::CheckRefundStatusWithUI(){
    GetXDGPaymentBridge()->CheckRefundStatusWithUI();
}


//安卓独有方法
void UXDGPaymentBPLibrary::RestorePurchase(FString purchaseToken,
                                        FString productId,
                                        FString orderId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    GetXDGPaymentBridge()->RestorePurchase(purchaseToken, productId, orderId, roleId, serverId, ext);
}


void UXDGPaymentBPLibrary::PayWithWeb(FString serverId,
                                      FString roleId){
    GetXDGPaymentBridge()->PayWithWeb(serverId, roleId);                                       
}


void UXDGPaymentBPLibrary::PayWithChannel(FString orderId,
                                        FString productId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    GetXDGPaymentBridge()->PayWithChannel(orderId, productId, roleId, serverId, ext);       
}

void UXDGPaymentBPLibrary::QueryInnerProductList(TArray<FString> productIds){
    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonOutString);
    Writer->WriteObjectStart();
    Writer->WriteValue(TEXT("list"), productIds);
    Writer->WriteObjectEnd();
    Writer->Close();
    GetXDGPaymentBridge()->QueryInnerProductList(JsonOutString);    
}

void UXDGPaymentBPLibrary::InlinePay(FString orderId,
								FString productId,
								FString productName,
								FString region,
								FString serverId,
								FString roleId,
								FString ext){
    GetXDGPaymentBridge()->InlinePay(orderId, productId, productName, region, serverId, roleId, ext);
}


//iOS独有方法
void UXDGPaymentBPLibrary::PurchaseToken(FString transactionIdentifier,
                                        FString productIdentifier,
                                        FString orderId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    GetXDGPaymentBridge()->PurchaseToken(transactionIdentifier, productIdentifier, orderId, roleId, serverId, ext);
}
