// Fill out your copyright notice in the Description page of Project Settings.
#if PLATFORM_IOS
#pragma once

#include "Core.h"
#include "CoreMinimal.h"
#include "XDGAccountBridge.h"

#import <Foundation/Foundation.h>
#import <XDGAccountSDK/XDGAccount.h>
#import <XDGCommonSDK/XDGUser.h>
#import <XDGCommonSDK/XDGAccessToken.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>

/**
 * 
 */
class XDGACCOUNT_API XDGAccountIOS : public XDGAccountBridge
{
public:
	XDGAccountIOS();
	~XDGAccountIOS();

	void Login();
	void LoginByType(FString loginType);
	void AddUserStatusChangeCallback();
    void GetUser();
	void OpenUserCenter();
	void Logout();
	void LoginSync();
};

@interface XDGUE4AccountTool : NSObject
+ (void)bridgeUserCallback:(XDGUser *)user error:(NSError *)error isLogin: (Boolean)isLogin;
@end

#endif 