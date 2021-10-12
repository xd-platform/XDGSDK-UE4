// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGPaymentIOS.h"

XDGPaymentIOS::XDGPaymentIOS()
{
}

XDGPaymentIOS::~XDGPaymentIOS()
{
}


//ios 安卓都有的方法
void XDGPaymentIOS::QueryWithProductIds(FString listJson){

}


void XDGPaymentIOS::PayWithProduct(FString orderId,
                            FString productId,
                            FString roleId,
                            FString serverId,
                            FString ext){

}


void XDGPaymentIOS::QueryRestoredPurchases(){

}


void XDGPaymentIOS::CheckRefundStatus(){

}


void XDGPaymentIOS::CheckRefundStatusWithUI(){

}


//安卓独有方法
void XDGPaymentIOS::RestorePurchase(FString purchaseToken,
                            FString productId,
                            FString orderId,
                            FString roleId,
                            FString serverId,
                            FString ext){

}


void XDGPaymentIOS::PayWithWeb(FString serverId,
                        FString roleId){

}


void XDGPaymentIOS::PayWithChannel(FString orderId,
                            FString productId,
                            FString roleId,
                            FString serverId,
                            FString ext){

}


//iOS独有方法
void XDGPaymentIOS::PurchaseToken(FString transactionIdentifier,
                            FString productIdentifier,
                            FString orderId,
                            FString roleId,
                            FString serverId,
                            FString ext){
                                
}