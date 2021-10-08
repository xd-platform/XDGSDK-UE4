// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XDGAccountBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDGACCOUNT_API UXDGAccountBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void Login();

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void LoginByType(FString loginType);

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void AddUserStatusChangeCallback();

    UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void GetUser();

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void OpenUserCenter();

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void Logout();

	UFUNCTION(BlueprintCallable, Category = "XDGAccount")
	static void LoginSync();
};
