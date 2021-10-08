// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "CoreMinimal.h"
#include "XDGAccountBridge.h"

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
