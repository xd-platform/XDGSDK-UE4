// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
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

	void OnXDGSDKInitSucceed();

    //0成功，1取消，2失败
    void OnXDGSDKShareSucceed(const int32);

};
