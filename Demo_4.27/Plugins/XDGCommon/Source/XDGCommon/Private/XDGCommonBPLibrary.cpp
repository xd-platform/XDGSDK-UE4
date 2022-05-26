// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGCommonBPLibrary.h"
#include "XDGCommonBridge.h"
#include "Engine.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

UXDGCommonBPLibrary::UXDGCommonBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}


FString UXDGCommonBPLibrary::GetSDKVersionName(){
    return GetXDGCommonBridge()->GetSDKVersionName();
}

void UXDGCommonBPLibrary::SetLanguage(int32 langType){
    GetXDGCommonBridge()->SetLanguage(langType);
}

void UXDGCommonBPLibrary::InitSDK(){
    GetXDGCommonBridge()->InitSDK();
}

bool UXDGCommonBPLibrary::IsInitialized(){
    return GetXDGCommonBridge()->IsInitialized();
}

void UXDGCommonBPLibrary::Report(FString serverId, FString roleId, FString roleName){
    GetXDGCommonBridge()->Report(serverId, roleId, roleName);
}

void UXDGCommonBPLibrary::StoreReview(){
    GetXDGCommonBridge()->StoreReview();
}


void UXDGCommonBPLibrary::ShareFlavors(int32 type, FString uri, FString message){
    GetXDGCommonBridge()->ShareFlavors(type, uri, message);
}

void UXDGCommonBPLibrary::ShareImage(int32 type, FString imagePath){
    GetXDGCommonBridge()->ShareImage(type, imagePath);
}


void UXDGCommonBPLibrary::TrackUser(FString userId){
    GetXDGCommonBridge()->TrackUser(userId);
}

void UXDGCommonBPLibrary::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){
    GetXDGCommonBridge()->TrackRole(serverId, roleId, roleName, level);
}

void UXDGCommonBPLibrary::TrackEvent(FString eventName){
    GetXDGCommonBridge()->TrackEvent(eventName);
}

void UXDGCommonBPLibrary::TrackAchievement(){
    GetXDGCommonBridge()->TrackAchievement();
}

void UXDGCommonBPLibrary::EventCompletedTutorial(){
    GetXDGCommonBridge()->EventCompletedTutorial();
}

void UXDGCommonBPLibrary::EventCreateRole(){
    GetXDGCommonBridge()->EventCreateRole();
}

void UXDGCommonBPLibrary::SetCurrentUserPushServiceEnable(bool enable){
    GetXDGCommonBridge()->SetCurrentUserPushServiceEnable(enable);
}

bool UXDGCommonBPLibrary::IsCurrentUserPushServiceEnable(){
   return GetXDGCommonBridge()->IsCurrentUserPushServiceEnable();
}

void UXDGCommonBPLibrary::GetRegionInfo(){
    GetXDGCommonBridge()->GetRegionInfo();
}

void UXDGCommonBPLibrary::EnableIDFA(){
    GetXDGCommonBridge()->EnableIDFA();

    //测试代码--start 
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,  TEXT("设置IDFA true"), true, FVector2D(2, 2));
    //测试代码--end
}

void UXDGCommonBPLibrary::RequestIDFA(){
    GetXDGCommonBridge()->RequestIDFA();
}

 void UXDGCommonBPLibrary::DevelopUrlInit(){
    GetXDGCommonBridge()->DevelopUrlInit();
 }

 void UXDGCommonBPLibrary::ShowTest(){
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,  TEXT("OnXDGSDKInitSucceed3 中文 ศูนย์ความปลอดภัยบัญชี"), true, FVector2D(2, 2));
    // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed 中文 ศูนย์ความปลอดภัยบัญชี");
}

