// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID

#include "XDGCommonAndroid.h"
#include "Engine.h"
#include "XDGCommon.h"

#define UNREAL4_CLASS_NAME_COMMON "com/xd/XDGCommonUnreal4"

XDGCommonAndroid::XDGCommonAndroid()
{
}

XDGCommonAndroid::~XDGCommonAndroid()
{
}


FString XDGCommonAndroid::GetSDKVersionName(){
    FString version = "";
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "getSDKVersionName";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()Ljava/lang/String;");
        if (jMethod)
        {
            auto jVersion = (jstring)(env->CallStaticObjectMethod(jXDSDKUnreal4Class, jMethod));
            const char *versionChar = env->GetStringUTFChars(jVersion, 0);
            version = ANSI_TO_TCHAR(versionChar);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    return version;
}


void XDGCommonAndroid::SetLanguage(int32 langType){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "setLanguage";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(I)V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, (jint)langType);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGCommonAndroid::InitSDK(){
   JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "initSDK";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Landroid/app/Activity;)V");
        if (jMethod)
        {
            auto jActivity = FAndroidApplication::GetGameActivityThis();
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jActivity);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


bool XDGCommonAndroid::IsInitialized(){
    bool isInitialized = false;
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "isInitialized";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()Z");
        if (jMethod)
        {
            isInitialized = (bool)(env->CallStaticBooleanMethod(jXDSDKUnreal4Class, jMethod));
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    return isInitialized;
}


void XDGCommonAndroid::Report(FString serverId, FString roleId, FString roleName){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "report";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jActivity = FAndroidApplication::GetGameActivityThis();
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jRoleName = env->NewStringUTF(TCHAR_TO_ANSI(*roleName));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jActivity, jServerId, jRoleId, jRoleName);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jRoleName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGCommonAndroid::StoreReview(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "storeReview";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGCommonAndroid::ShareFlavors(int32 type, FString uri, FString message){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "shareFlavors";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(ILjava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jUri = env->NewStringUTF(TCHAR_TO_ANSI(*uri));
            auto jMessage = env->NewStringUTF(TCHAR_TO_ANSI(*message));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, (jint)type, jUri, jMessage);
            env->DeleteLocalRef(jUri);
            env->DeleteLocalRef(jMessage);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    
}


void XDGCommonAndroid::ShareImage(int32 type, FString imagePath){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "shareImage";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(ILjava/lang/String;)V");
        if (jMethod)
        {
            auto jImagePath = env->NewStringUTF(TCHAR_TO_ANSI(*imagePath));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, (jint)type, jImagePath);
            env->DeleteLocalRef(jImagePath);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGCommonAndroid::TrackUser(FString userId){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackUser";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jUserId = env->NewStringUTF(TCHAR_TO_ANSI(*userId));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jUserId);
            env->DeleteLocalRef(jUserId);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDGCommonAndroid::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){

    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackRole";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
        if (jMethod)
        {
            auto jActivity = FAndroidApplication::GetGameActivityThis();
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jRoleName = env->NewStringUTF(TCHAR_TO_ANSI(*roleName));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jActivity, jServerId, jRoleId, jRoleName, (jint)level);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jRoleName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    
}


void XDGCommonAndroid::TrackEvent(FString eventName){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackEvent";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jEventName = env->NewStringUTF(TCHAR_TO_ANSI(*eventName));
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jEventName);
            
            env->DeleteLocalRef(jEventName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGCommonAndroid::TrackAchievement(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackAchievement";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGCommonAndroid::EventCompletedTutorial(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "eventCompletedTutorial";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGCommonAndroid::EventCreateRole(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "eventCreateRole";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


void XDGCommonAndroid::SetCurrentUserPushServiceEnable(bool enable){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "setCurrentUserPushServiceEnable";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Z)V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, (jboolean)enable);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


bool XDGCommonAndroid::IsCurrentUserPushServiceEnable(){
    bool isEnable = false;
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "isCurrentUserPushServiceEnable";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()Z");
        if (jMethod)
        {
            isEnable = (bool)(env->CallStaticBooleanMethod(jXDSDKUnreal4Class, jMethod));
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    return isEnable;
}


void XDGCommonAndroid::GetRegionInfo(){

}

#ifdef __cplusplus
extern "C"
{
#endif

  __attribute__((visibility("default"))) void Java_com_xd_XDGCommonUnreal4_nativeOnXDGSDKInitSucceed(JNIEnv *jenv, jclass thiz, jboolean success)
    {
        FXDGCommonModule::OnXDGSDKInitSucceed.Broadcast((bool)success);
    }

  __attribute__((visibility("default"))) void Java_com_xd_XDGCommonUnreal4_nativeOnXDGSDKShareCompleted(JNIEnv *jenv, jclass thiz, int32 code)
    {
        FXDGCommonModule::OnXDGSDKShareCompleted.Broadcast((int)code);
    }

#ifdef __cplusplus
}
#endif

#endif