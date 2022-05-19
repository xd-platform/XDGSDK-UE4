// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#pragma once

#include "Core.h"
#include "CoreMinimal.h"
#include "XDGCommonBridge.h"

#import <Foundation/Foundation.h>
#import <XDGCommonSDK/XDGSDK.h>
#import <XDGCommonSDK/XDGShare.h>
#import <XDGCommonSDK/XDGMessageManager.h>
#import <XDGCommonSDK/XDGTrackerManager.h>
#import <XDGCommonSDK/XDGSDKSettings.h>
#import <XDGCommonSDK/XDGGameDataManager.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>
#import <XDGCommonSDK/XDGCoreService.h>


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
	void GetRegionInfo();

	 void DevelopUrlInit();
};

@interface XDGUE4CommonTool : NSObject
+ (void)shareWithResult:(NSError *)error cancel:(BOOL)cancel;
@end

#endif