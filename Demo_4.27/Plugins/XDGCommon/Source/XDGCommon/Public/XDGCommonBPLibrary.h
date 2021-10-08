// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XDGCommonBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDGCOMMON_API UXDGCommonBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
    static FString GetSDKVersionName();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void SetLanguage(int32 langType);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void InitSDK();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static bool IsInitialized();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void Report(FString serverId, FString roleId, FString roleName);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void StoreReview();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void ShareFlavors(int32 type, FString uri, FString message);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void ShareImage(int32 type, FString imagePath);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void TrackUser(FString userId);
	
	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void TrackRole(FString serverId, FString roleId, FString roleName, int32 level);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void TrackEvent(FString eventName);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void TrackAchievement();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void EventCompletedTutorial();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void EventCreateRole();

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static void SetCurrentUserPushServiceEnable(bool enable);

	UFUNCTION(BlueprintCallable, Category = "XDGCommon")
	static bool IsCurrentUserPushServiceEnable();
};
