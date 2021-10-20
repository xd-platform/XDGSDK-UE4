// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "Modules/ModuleManager.h"
#include "CoreUObject.h"
#include "Engine.h"

class XDGCOMMON_API FXDGCommonModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	 static inline FXDGCommonModule& Get(){
            return FModuleManager::LoadModuleChecked<FXDGCommonModule>( "XDGCommon" );
      }
    
      static inline bool IsAvailable(){
            return FModuleManager::Get().IsModuleLoaded( "XDGCommon" );
      }

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKInitSucceed, const bool);
	DECLARE_MULTICAST_DELEGATE_OneParam(FXDGSDKShareCompleted, const int32);
   

    UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
    static FXDGSDKInitSucceed OnXDGSDKInitSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
    static FXDGSDKShareCompleted OnXDGSDKShareCompleted;
	

};
