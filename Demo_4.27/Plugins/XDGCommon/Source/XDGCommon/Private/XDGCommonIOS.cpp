// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGCommonIOS.h"

XDGCommonIOS::XDGCommonIOS()
{
}

XDGCommonIOS::~XDGCommonIOS()
{
}


FString XDGCommonIOS::GetSDKVersionName(){
    return "1.0";
}

void XDGCommonIOS::SetLanguage(int32 langType){
    
}

void XDGCommonIOS::InitSDK(){
    
}

bool XDGCommonIOS::IsInitialized(){
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