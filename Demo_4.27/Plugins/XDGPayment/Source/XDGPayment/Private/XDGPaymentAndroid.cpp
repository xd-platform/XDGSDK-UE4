// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#include "XDGPaymentAndroid.h"

#include "Engine.h"
#include "XDGPayment.h"

#define UNREAL4_CLASS_NAME_PAYMENT "com/xd/XDGPaymentUnreal4"

XDGPaymentAndroid::XDGPaymentAndroid()
{
}

XDGPaymentAndroid::~XDGPaymentAndroid()
{
}

//ios 安卓都有的方法
void XDGPaymentAndroid::QueryWithProductIds(FString listJson){
     JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "queryWithProductIds";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jListJson = env->NewStringUTF(TCHAR_TO_ANSI(*listJson));
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jListJson);
            env->DeleteLocalRef(jListJson);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}

void XDGPaymentAndroid::PayWithProduct(FString orderId,
                                        FString productId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "payWithProduct";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jOrderId = env->NewStringUTF(TCHAR_TO_ANSI(*orderId));
            auto jProductId = env->NewStringUTF(TCHAR_TO_ANSI(*productId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jExt = env->NewStringUTF(TCHAR_TO_ANSI(*ext));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jOrderId, jProductId, jRoleId, jServerId, jExt);

            env->DeleteLocalRef(jOrderId);
            env->DeleteLocalRef(jProductId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jExt);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGPaymentAndroid::QueryRestoredPurchases(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "queryRestoredPurchases";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGPaymentAndroid::CheckRefundStatus(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "checkRefundStatus";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGPaymentAndroid::CheckRefundStatusWithUI(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "checkRefundStatusWithUI";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}

void XDGPaymentAndroid::QueryInnerProductList(FString listJson){//安卓内嵌支付用
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "queryProductList";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jListJson = env->NewStringUTF(TCHAR_TO_ANSI(*listJson));
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jListJson);
            env->DeleteLocalRef(jListJson);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
     
} 

void XDGPaymentAndroid::InlinePay(FString orderId,  
								FString productId,
								FString productName,
								FString region,
								FString serverId,
								FString roleId,
								FString ext){

    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "inlinePay";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jOrderId = env->NewStringUTF(TCHAR_TO_ANSI(*orderId));
            auto jProductId = env->NewStringUTF(TCHAR_TO_ANSI(*productId));
            auto jProductName = env->NewStringUTF(TCHAR_TO_ANSI(*productName));
            auto jRegion = env->NewStringUTF(TCHAR_TO_ANSI(*region));
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jExt = env->NewStringUTF(TCHAR_TO_ANSI(*ext));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jOrderId, jProductId, jProductName, jRegion, jServerId, jRoleId, jExt);

            env->DeleteLocalRef(jOrderId);
            env->DeleteLocalRef(jProductId);
            env->DeleteLocalRef(jProductName);
            env->DeleteLocalRef(jRegion);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jExt);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    
}


//安卓独有方法
void XDGPaymentAndroid::RestorePurchase(FString purchaseToken,
                                        FString productId,
                                        FString orderId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "restorePurchase";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jPurchaseToken = env->NewStringUTF(TCHAR_TO_ANSI(*purchaseToken));
            auto jProductId = env->NewStringUTF(TCHAR_TO_ANSI(*productId));
            auto jOrderId = env->NewStringUTF(TCHAR_TO_ANSI(*orderId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jExt = env->NewStringUTF(TCHAR_TO_ANSI(*ext));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jPurchaseToken, jProductId, jOrderId, jRoleId, jServerId, jExt);

            env->DeleteLocalRef(jPurchaseToken);
            env->DeleteLocalRef(jProductId);
            env->DeleteLocalRef(jOrderId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jExt);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGPaymentAndroid::PayWithWeb(FString serverId,
                                   FString roleId){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "payWithWeb";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jServerId, jRoleId);

            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGPaymentAndroid::PayWithChannel(FString orderId,
                                    FString productId,
                                    FString roleId,
                                    FString serverId,
                                    FString ext){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "payWithChannel";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jOrderId = env->NewStringUTF(TCHAR_TO_ANSI(*orderId));
            auto jProductId = env->NewStringUTF(TCHAR_TO_ANSI(*productId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jExt = env->NewStringUTF(TCHAR_TO_ANSI(*ext));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jOrderId, jProductId, jRoleId, jServerId, jExt);

            env->DeleteLocalRef(jOrderId);
            env->DeleteLocalRef(jProductId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jExt);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


//iOS独有方法
void XDGPaymentAndroid::PurchaseToken(FString transactionIdentifier,
                                    FString productIdentifier,
                                    FString orderId,
                                    FString roleId,
                                    FString serverId,
                                    FString ext){
     //安卓没有                           
}



#ifdef __cplusplus
extern "C"
{
#endif

    __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKPaymentSucceed(JNIEnv *jenv, jclass thiz, jstring orderId, jstring productId, jstring serverId, jstring roleId)
    {
        const char *cOrderId = jenv->GetStringUTFChars(orderId, 0);
        FString fOrderId = UTF8_TO_TCHAR(cOrderId);

        const char *cProductId = jenv->GetStringUTFChars(productId, 0);
        FString fProductId = UTF8_TO_TCHAR(cProductId);

        const char *cServerId = jenv->GetStringUTFChars(serverId, 0);
        FString fServerId = UTF8_TO_TCHAR(cServerId);

        const char *cRoleId = jenv->GetStringUTFChars(roleId, 0);
        FString fRoleId = UTF8_TO_TCHAR(cRoleId);

        FXDGPaymentModule::OnXDGSDKPaymentSucceed.Broadcast(fOrderId, fProductId, fServerId, fRoleId);

        jenv->ReleaseStringUTFChars(orderId, cOrderId);
        jenv->ReleaseStringUTFChars(productId, cProductId);
        jenv->ReleaseStringUTFChars(serverId, cServerId);
        jenv->ReleaseStringUTFChars(roleId, cRoleId);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKPaymentFailed(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
        const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDGPaymentModule::OnXDGSDKPaymentFailed.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }

     __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryProductIdsSucceed(JNIEnv *jenv, jclass thiz, jstring resultJson)
    {
        const char *cJson = jenv->GetStringUTFChars(resultJson, 0);
        FString fJson = UTF8_TO_TCHAR(cJson);
        FXDGPaymentModule::OnXDGSDKQueryProductIdsSucceed.Broadcast(fJson);
        jenv->ReleaseStringUTFChars(resultJson, cJson);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryProductIdsFailed(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
        const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDGPaymentModule::OnXDGSDKQueryProductIdsFailed.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }

   __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryInnerProductsSucceed(JNIEnv *jenv, jclass thiz, jstring resultJson)
    {
        const char *cJson = jenv->GetStringUTFChars(resultJson, 0);
        FString fJson = UTF8_TO_TCHAR(cJson);
        FXDGPaymentModule::OnXDGSDKQueryInnerProductsSucceed.Broadcast(fJson);
        jenv->ReleaseStringUTFChars(resultJson, cJson);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryInnerProductsFailed(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
        const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDGPaymentModule::OnXDGSDKQueryInnerProductsFailed.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKInlinePayPaymentCompleted(JNIEnv *jenv, jclass thiz, jstring resultJson)
    {
        const char *cJson = jenv->GetStringUTFChars(resultJson, 0);
        FString fJson = UTF8_TO_TCHAR(cJson);
        FXDGPaymentModule::OnXDGSDKInlinePayPaymentCompleted.Broadcast(fJson);
        jenv->ReleaseStringUTFChars(resultJson, cJson);
    }

     __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryRestoredPurchasesSucceed(JNIEnv *jenv, jclass thiz, jstring resultJson)
    {
        const char *cJson = jenv->GetStringUTFChars(resultJson, 0);
        FString fJson = UTF8_TO_TCHAR(cJson);
        FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesSucceed.Broadcast(fJson);
        jenv->ReleaseStringUTFChars(resultJson, cJson);
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKQueryRestoredPurchasesFailed(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
        const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesFailed.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKPayWithWebCompleted(JNIEnv *jenv, jclass thiz, jstring serverId, jstring roleId, int32 code, jstring errorMsg)
    {
        const char *cServerId = jenv->GetStringUTFChars(serverId, 0);
        FString fServerId = UTF8_TO_TCHAR(cServerId);

        const char *cRoleId = jenv->GetStringUTFChars(roleId, 0);
        FString fRoleId = UTF8_TO_TCHAR(cRoleId);

        const char *cErrorMsg = jenv->GetStringUTFChars(errorMsg, 0);
        FString fErrorMsg = UTF8_TO_TCHAR(cErrorMsg);

        FXDGPaymentModule::OnXDGSDKPayWithWebCompleted.Broadcast(fServerId, fRoleId, (int)code, fErrorMsg);

        jenv->ReleaseStringUTFChars(serverId, cServerId);
        jenv->ReleaseStringUTFChars(roleId, cRoleId);
        jenv->ReleaseStringUTFChars(errorMsg, cErrorMsg);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKCheckRefundStatusSucceed(JNIEnv *jenv, jclass thiz, jstring resultJson)
    {
        const char *cJson = jenv->GetStringUTFChars(resultJson, 0);
        FString fJson = UTF8_TO_TCHAR(cJson);
        FXDGPaymentModule::OnXDGSDKCheckRefundStatusSucceed.Broadcast(fJson);
        jenv->ReleaseStringUTFChars(resultJson, cJson);
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDGPaymentUnreal4_nativeOnXDGSDKCheckRefundStatusFailed(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
        const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDGPaymentModule::OnXDGSDKCheckRefundStatusFailed.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }

#ifdef __cplusplus
}
#endif


#endif