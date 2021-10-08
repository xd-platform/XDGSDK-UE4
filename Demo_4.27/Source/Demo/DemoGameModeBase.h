// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API ADemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

    //XDGCommon
	void OnXDGSDKInitSucceed(const bool);

    //0成功，1取消，2失败
    void OnXDGSDKShareSucceed(const int32);

    //XDGAccount 
	void OnXDGSDKLoginSucceed(const FString&);

	void OnXDGSDKLoginFailed(const int32, const FString&);

	void OnXDGSDKGetUserSucceed(const FString&);

	void OnXDGSDKGetUserFailed(const int32, const FString&);

	void OnXDGSDKUserStateChanged(const int32, const FString&);

	void OnXDGSDKLoginSync(const FString&);
};
