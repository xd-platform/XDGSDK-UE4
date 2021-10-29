// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#pragma once

#include "Core.h"
#include "XDGCommonBridge.h"

// #include "Android/AndroidJNI.h"
// #include "Android/AndroidApplication.h"
// #include "Android/AndroidJava.h"

#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#include "Runtime/Core/Public/Android/AndroidJava.h"


/**

 */
class  XDGCommonAndroid : public XDGCommonBridge
{
public:
	XDGCommonAndroid();
	~XDGCommonAndroid();

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

	void GetRegionInfo();
};
#endif 