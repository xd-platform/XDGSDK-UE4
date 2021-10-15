// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "CoreMinimal.h"
#include "XDGCommonBridge.h"

#import <XDGCommonSDK/XDGSDK.h>

/**

 */
class  XDGCommonIOS : public XDGCommonBridge
{
public:
	XDGCommonIOS();
	~XDGCommonIOS();

	FString GetSDKVersionName();
	void SetLanguage(int32 langType);
	void InitSDK();
	bool IsInitialized();
	void Report(FString serverId, FString roleId, FString roleName);
	void StoreReview();

	void ShareFlavors(int32 type, FString uri, FString message);
	void ShareImage(int32 type, FString imagePath);

	void TrackUser(FString userId);
	void TrackRole(FString serverId, FString roleId, FString roleName, int32 level);
	void TrackEvent(FString eventName);
	void TrackAchievement();
	void EventCompletedTutorial();
	void EventCreateRole();

	void SetCurrentUserPushServiceEnable(bool enable);
	bool IsCurrentUserPushServiceEnable();
};
