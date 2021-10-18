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
        if (error != nil) {
            FXDGAccountModule::OnXDGSDKLoginFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
            NSLog(@"登录失败：%@", error.localizedDescription?:@"");

        }else{
            NSString* res = [XDGAccountTool bridgeUserCallback:result error:error];
            FXDGAccountModule::OnXDGSDKLoginSucceed.Broadcast(UTF8_TO_TCHAR([res UTF8String]));
            NSLog(@"登录成功：%@", res);
        }
    }];
}

void XDGAccountIOS::LoginByType(FString loginType){

}

void XDGAccountIOS::AddUserStatusChangeCallback(){
}

void XDGAccountIOS::GetUser(){
}

void XDGAccountIOS::OpenUserCenter(){
}

void XDGAccountIOS::Logout(){
}

void XDGAccountIOS::LoginSync(){
}


//-------ios 源代码-------
@implementation XDGAccountTool

+ (NSString *)bridgeUserCallback:(XDGUser *)user error:(NSError *)error {
    NSMutableDictionary *resultDic = [NSMutableDictionary dictionary];
    if (user) {
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
        
        [resultDic setObject:userDic forKey:@"user"];
    }
    
    if (error) {
        NSDictionary *errorDic = @{
            @"code":@(error.code),
            @"error_msg":error.localizedDescription?:@""
        };
        [resultDic setObject:errorDic forKey:@"error"];
    }
    
    return resultDic.tdsglobal_jsonString;
}

@end

#endif 