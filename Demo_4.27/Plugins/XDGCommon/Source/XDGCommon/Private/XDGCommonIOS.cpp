// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDGCommonIOS.h"
#include "Engine.h"
#include "XDGCommon.h"

#import <Foundation/Foundation.h>
#import <XDGCommonSDK/XDGSDK.h>
#import <XDGCommonSDK/XDGShare.h>
#import <XDGCommonSDK/XDGMessageManager.h>
#import <XDGCommonSDK/XDGTrackerManager.h>
#import <XDGCommonSDK/XDGSDKSettings.h>
#import <XDGCommonSDK/XDGGameDataManager.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>


XDGCommonIOS::XDGCommonIOS()
{
}

XDGCommonIOS::~XDGCommonIOS()
{
}


FString XDGCommonIOS::GetSDKVersionName(){
    FString version = "";
    NSString * nVersion = [XDGSDK getSDKVersionName];
    version = UTF8_TO_TCHAR([nVersion UTF8String]);
    NSLog(@"获取版本号 %@", nVersion);
    return version;
}

void XDGCommonIOS::SetLanguage(int32 langType){
    [XDGSDKSettings setLanguage:XDGLanguageLocaleSimplifiedChinese];
     NSLog(@"设置语言 %d", langType);
}

void XDGCommonIOS::InitSDK(){
    [XDGSDK initSDK:^(BOOL success) {
        if (success) {
            NSLog(@"初始化 成功");
        }else {
            NSLog(@"初始化 失败");
        }
        FXDGCommonModule::OnXDGSDKInitSucceed.Broadcast((bool)success);
    }];
}

bool XDGCommonIOS::IsInitialized(){
    bool isLoggedIn = false;
    isLoggedIn = [XDGGameDataManager isGameInited];
    NSLog(@"是否初始化了 %d", isLoggedIn);
    return isLoggedIn;
    return true;
}

void XDGCommonIOS::Report(FString serverId, FString roleId, FString roleName){
    
}

void XDGCommonIOS::StoreReview(){
    
}

void XDGCommonIOS::ShareFlavors(int32 type, FString uri, FString message){
    
}

void XDGCommonIOS::ShareImage(int32 type, FString imagePath){
    
}

void XDGCommonIOS::TrackUser(FString userId){
    
}

void XDGCommonIOS::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){
    
}

void XDGCommonIOS::TrackEvent(FString eventName){
    
}

void XDGCommonIOS::TrackAchievement(){
    
}

void XDGCommonIOS::EventCompletedTutorial(){
    
}

void XDGCommonIOS::EventCreateRole(){
    
}

void XDGCommonIOS::SetCurrentUserPushServiceEnable(bool enable){
    
}

bool XDGCommonIOS::IsCurrentUserPushServiceEnable(){
    return true;
}


#endif