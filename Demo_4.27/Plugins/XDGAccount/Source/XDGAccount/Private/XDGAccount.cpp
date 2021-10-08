// Copyright Epic Games, Inc. All Rights Reserved.

#include "XDGAccount.h"

#define LOCTEXT_NAMESPACE "FXDGAccountModule"

FXDGAccountModule::FXDGSDKLoginSucceed FXDGAccountModule::OnXDGSDKLoginSucceed;
FXDGAccountModule::FXDGSDKLoginFailed FXDGAccountModule::OnXDGSDKLoginFailed;
FXDGAccountModule::FXDGSDKGetUserSucceed FXDGAccountModule::OnXDGSDKGetUserSucceed;
FXDGAccountModule::FXDGSDKGetUserFailed FXDGAccountModule::OnXDGSDKGetUserFailed;
FXDGAccountModule::FXDGSDKUserStateChanged FXDGAccountModule::OnXDGSDKUserStateChanged;
FXDGAccountModule::FXDGSDKLoginSync FXDGAccountModule::OnXDGSDKLoginSync;

IMPLEMENT_MODULE(FXDGAccountModule, XDGAccount)
void FXDGAccountModule::StartupModule()
{

}

void FXDGAccountModule::ShutdownModule()
{
	
}
#undef LOCTEXT_NAMESPACE
	
