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
   [XDGUE4AccountTool enableTap:^{
        dispatch_async(dispatch_get_main_queue(), ^{
          [XDGAccount login:^(XDGUser * _Nullable result, NSError * _Nullable error) {
             [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: YES];
           }]; 
        });
    }];
}

void XDGAccountIOS::LoginByType(FString loginType){
    [XDGUE4AccountTool enableTap:^{
        dispatch_async(dispatch_get_main_queue(), ^{
          LoginEntryType type = [XDGEntryType entryTypeByString:loginType.GetNSString()];
          [XDGAccount loginByType:type loginHandler:^(XDGUser * _Nullable result, NSError * _Nullable error) {
              [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: YES];
          }]; 
       });
    }];
}

void XDGAccountIOS::AddUserStatusChangeCallback(){
    [XDGAccount addUserStatusChangeCallback:^(XDGUserStateChangeCode userStateChangeCode,NSString *message) {
        NSLog(@"添加回调 %d  %@", (int)userStateChangeCode, message);
        FXDGAccountModule::OnXDGSDKUserStateChanged.Broadcast((int)userStateChangeCode, UTF8_TO_TCHAR([message?:@"" UTF8String]));
    }];
}

void XDGAccountIOS::GetUser(){
    [XDGAccount getUser:^(XDGUser * _Nullable result, NSError * _Nullable error) {
        [XDGUE4AccountTool bridgeUserCallback:result error:error isLogin: NO];
    }];
}

void XDGAccountIOS::OpenUserCenter(){
     dispatch_async(dispatch_get_main_queue(), ^{
        [XDGAccount openUserCenter];
        NSLog(@"打开用户中心");
    });
}

void XDGAccountIOS::Logout(){
    dispatch_async(dispatch_get_main_queue(), ^{
        [XDGAccount logout];
        NSLog(@"点击退出登录");
    });
}

//打开注销页面
void XDGAccountIOS::OpenAccountCancellation(){
     dispatch_async(dispatch_get_main_queue(), ^{
        [XDGAccount accountCancellation];
        NSLog(@"打开注销页面");
    });
}



//-------ios 源代码-------
@implementation XDGUE4AccountTool
NSTimeInterval lastClick;        //防止重复点击
NSTimeInterval gapTime = 1000;   //点击间隔毫秒 

+ (void)enableTap:(VoidTapCallback) block{
    NSTimeInterval time = [[NSDate date] timeIntervalSince1970] * 1000;
    if ((time - lastClick) > gapTime) {
        lastClick = time;
        block();
    }
}

+ (void)bridgeUserCallback:(XDGUser *)user error:(NSError *)error isLogin: (Boolean)isLogin{
    if (error != nil) {
        if(isLogin){
            FXDGAccountModule::OnXDGSDKLoginFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
        }else{
            FXDGAccountModule::OnXDGSDKGetUserFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
        }   
        NSLog(@"失败：%@", error.localizedDescription?:@"");

    }else if(user != nil){
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

        //测试代码--start
        NSString* uid = user.userId;
        NSUserDefaults* df = [NSUserDefaults standardUserDefaults];
        [df setValue:uid forKey:@"demo_tmp_userId"];
        [df synchronize];
        NSLog(@"saved userId df get:%@", [df objectForKey:@"demo_tmp_userId"]);
        //测试代码--end

    }else{
        if(isLogin){
            FXDGAccountModule::OnXDGSDKLoginFailed.Broadcast(-1, "失败");
        }else{
            FXDGAccountModule::OnXDGSDKGetUserFailed.Broadcast(-1, "失败");
        }   
        
        NSLog(@"失败2");
    }
}

@end

#endif 
