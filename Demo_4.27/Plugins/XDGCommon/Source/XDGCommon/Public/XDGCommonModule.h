// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "Modules/ModuleManager.h"
#include "CoreUObject.h"
#include "Engine.h"

class XDGCOMMON_API XDGCommonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	 static inline XDGCommonModule& Get(){
            return FModuleManager::LoadModuleChecked<XDGCommonModule>( "XDGCommon" );
      }
    
      static inline bool IsAvailable(){
            return FModuleManager::Get().IsModuleLoaded( "XDGCommon" );
      }

	DECLARE_MULTICAST_DELEGATE(FXDGSDKInitSucceed);
	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKShareSucceed, const int32);
   

    UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
    static FXDGSDKInitSucceed OnXDGSDKInitSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
    static FXDGSDKShareSucceed OnXDGSDKShareSucceed;
	

};
