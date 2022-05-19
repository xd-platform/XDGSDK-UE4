// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDGCommonBridge
{
public:
	virtual FString GetSDKVersionName() = 0;
	virtual void SetLanguage(int32 langType) = 0;
	virtual void InitSDK() = 0;
	virtual bool IsInitialized() = 0;
	virtual void Report(FString serverId, FString roleId, FString roleName) = 0;
	virtual void StoreReview() = 0;

	virtual void ShareFlavors(int32 type, FString uri, FString message) = 0;
	virtual void ShareImage(int32 type, FString imagePath) = 0;

	virtual void TrackUser(FString userId) = 0;
	virtual void TrackRole(FString serverId, FString roleId, FString roleName, int32 level) = 0;
	virtual void TrackEvent(FString eventName) = 0;
	virtual void TrackAchievement() = 0;
	virtual void EventCompletedTutorial() = 0;
	virtual void EventCreateRole() = 0;

	virtual void SetCurrentUserPushServiceEnable(bool enable) = 0;
	virtual bool IsCurrentUserPushServiceEnable() = 0;

	virtual void GetRegionInfo() = 0;

	virtual void DevelopUrlInit() = 0; //设置测试环境url初始化,开发测试用，发布版里面实现会注销
	
};

XDGCommonBridge *GetXDGCommonBridge();