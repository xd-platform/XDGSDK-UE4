// Fill out your copyright notice in the Description page of Project Settings.


#include "XDGAccountBPLibrary.h"
#include "XDGAccountBridge.h"
#include "Engine.h"

#include "TapCommon.h"
#include "TapJson.h"
#include "TapBridge.h"


UXDGAccountBPLibrary::UXDGAccountBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}

void UXDGAccountBPLibrary::Login(){
    GetXDGAccountBridge()->Login();
}

void UXDGAccountBPLibrary::LoginByType(FString loginType){
    GetXDGAccountBridge()->LoginByType(loginType);
}

void UXDGAccountBPLibrary::AddUserStatusChangeCallback(){
    GetXDGAccountBridge()->AddUserStatusChangeCallback();
}

void UXDGAccountBPLibrary::GetUser(){
    GetXDGAccountBridge()->GetUser();
}

void UXDGAccountBPLibrary::OpenUserCenter(){
    GetXDGAccountBridge()->OpenUserCenter();
}

void UXDGAccountBPLibrary::Logout(){
    GetXDGAccountBridge()->Logout();
    
#if PLATFORM_ANDROID || PLATFORM_IOS
    FString commandJson = TapJson::ConstructorCommand(TEXT("TapBootstrapService"),TEXT("logout"),TEXT(""),false,TEXT(""),false);
    GetBridge()->CallHandler(commandJson);
#endif
}

void UXDGAccountBPLibrary::LoginSync(){
    GetXDGAccountBridge()->LoginSync();
}
