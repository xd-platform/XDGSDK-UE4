// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDGAccountIOS.h"

#include "Engine.h"
#include "XDGAccount.h"


XDGAccountIOS::XDGAccountIOS()
{
}

XDGAccountIOS::~XDGAccountIOS()
{
}

void XDGAccountIOS::Login(){
     [XDGAccount login:^(XDGUser * _Nullable result, NSError * _Nullable error) {
        [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: YES];
    }];
}

void XDGAccountIOS::LoginByType(FString loginType){
    LoginEntryType type = [XDGEntryType entryTypeByString:loginType.GetNSString()];
    [XDGAccount loginByType:type loginHandler:^(XDGUser * _Nullable result, NSError * _Nullable error) {
        [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: YES];
    }];
}

void XDGAccountIOS::AddUserStatusChangeCallback(){
    [XDGAccount addUserStatusChangeCallback:^(XDGUserStateChangeCode userStateChangeCode,NSString *message) {
        FXDGAccountModule::OnXDGSDKUserStateChanged.Broadcast((int)userStateChangeCode, UTF8_TO_TCHAR([message?:@"" UTF8String]));
    }];
}

void XDGAccountIOS::GetUser(){
    [XDGAccount getUser:^(XDGUser * _Nullable result, NSError * _Nullable error) {
        [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: NO];
    }];
}

void XDGAccountIOS::OpenUserCenter(){
    [XDGAccount openUserCenter];
}

void XDGAccountIOS::Logout(){
    dispatch_async(dispatch_get_main_queue(), ^{
        [XDGAccount logout];
    });
}

void XDGAccountIOS::LoginSync(){
    [XDGAccount loginSync:^(NSDictionary * _Nullable result, NSError * _Nullable error) {
        NSString* sessionToken = @"";
        if(result != nil){
          sessionToken = [result objectForKey:@"sessionToken"];
        }
        FXDGAccountModule::OnXDGSDKLoginSync.Broadcast(UTF8_TO_TCHAR([sessionToken UTF8String]));
    }];
}

//-------ios 源代码-------
@implementation XDGUE4AccountTool

+ (void)bridgeUserCallback:(XDGUser *)user error:(NSError *)error isLogin: (Boolean)isLogin{
    if (error != nil) {
        if(isLogin){
            FXDGAccountModule::OnXDGSDKLoginFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
        }else{
            FXDGAccountModule::OnXDGSDKGetUserFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
        }   
        NSLog(@"失败：%@", error.localizedDescription?:@"");
    }else{
         NSDictionary *userDic = @{
            @"userId":user.userId,
            @"name":user.name?:@"",
            @"loginType":user.loginType,
            @"boundAccounts":user.boundAccounts?:@[],
            @"token":@{
                    @"kid":user.token.kid?:@"",
                    @"tokenType":user.token.tokenType?:@"",
                    @"macKey":user.token.macKey?:@"",
                    @"macAlgorithm":user.token.macAlgorithm?:@"",
            }
        };
        NSString* res = userDic.tdsglobal_jsonString;

        if(isLogin){
            FXDGAccountModule::OnXDGSDKLoginSucceed.Broadcast(UTF8_TO_TCHAR([res UTF8String]));
        }else{
            FXDGAccountModule::OnXDGSDKGetUserSucceed.Broadcast(UTF8_TO_TCHAR([res UTF8String]));
        }   
        NSLog(@"成功：%@", res);
    }
}

@end

#endif 