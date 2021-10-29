// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGCommonBPLibrary.h"
#include "XDGCommonBridge.h"
#include "Engine.h"

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

