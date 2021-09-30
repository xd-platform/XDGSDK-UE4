// Copyright Epic Games, Inc. All Rights Reserved.

#include "XDGCommonModule.h"

#define LOCTEXT_NAMESPACE "XDGCommon"

XDGCommonModule::FXDGSDKInitSucceed XDGCommonModule::OnXDGSDKInitSucceed;
XDGCommonModule::FXDGSDKShareSucceed XDGCommonModule::OnXDGSDKShareSucceed;

void XDGCommonModule::StartupModule()
{

}

void XDGCommonModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(XDGCommonModule, XDGCommon)
