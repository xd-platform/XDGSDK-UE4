// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDGCommonIOS.h"
#include "Engine.h"
#include "XDGCommon.h"


XDGCommonIOS::XDGCommonIOS()
{
}

XDGCommonIOS::~XDGCommonIOS()
{
}

FString XDGCommonIOS::GetSDKVersionName(){
    FString version = "";
    NSString * nVersion = [XDGSDK getSDKVersionName];
    version = UTF8_TO_TCHAR([nVersion UTF8String]);
    NSLog(@"获取版本号 %@", nVersion);
    return version;
}

void XDGCommonIOS::SetLanguage(int32 langType){
    XDGLanguageLocale type = XDGLanguageLocaleSimplifiedChinese;
    switch (langType) {
        case 1:
            type = XDGLanguageLocaleTraditionalChinese;
            break;
        case 2:
            type = XDGLanguageLocaleEnglish;
            break;
        case 3:
            type = XDGLanguageLocaleThai;
            break;
        case 4:
            type = XDGLanguageLocaleBahasa;
            break;
        case 5:
            type = XDGLanguageLocaleKorean;
            break;
        case 6:
            type = XDGLanguageLocaleJapanese;
            break;
        case 7:
            type = XDGLanguageLocaleGerman;
            break;
        case 8:
            type = XDGLanguageLocaleFrench;
            break;
        case 9:
            type = XDGLanguageLocalePortuguese;
            break;
        case 10:
            type = XDGLanguageLocaleSpanish;
            break;
        case 11:
            type = XDGLanguageLocaleTurkish;
            break;
        case 12:
            type = XDGLanguageLocaleRussian;
            break;  
        default:
            type = XDGLanguageLocaleSimplifiedChinese;
            break;
    }
    [XDGSDKSettings setLanguage:type];
     NSLog(@"设置语言 %d", langType);
}

void XDGCommonIOS::InitSDK(){
    [XDGSDK initSDK:^(BOOL success) {
        if (success) {
            NSLog(@"初始化 成功");
        }else {
            NSLog(@"初始化 失败");
        }
        FXDGCommonModule::OnXDGSDKInitSucceed.Broadcast((bool)success);
    }];
}

bool XDGCommonIOS::IsInitialized(){
    bool isLoggedIn = false;
    isLoggedIn = [XDGGameDataManager isGameInited];
    NSLog(@"是否初始化了 %d", isLoggedIn);

    [XDGSDK trackRoleWithRoleId:@"roleId" roleName:@"roleName" serverId:@"serverId" level:0];
    [XDGSDK trackEvent:@"eventName" properties:@{@"test":@"test"}];
    [XDGSDK trackAchievement];
    [XDGSDK eventCreateRole];
    [XDGSDK eventCompletedTutorial];
    NSLog(@"点击 Test");

    return isLoggedIn;
}

void XDGCommonIOS::Report(FString serverId, FString roleId, FString roleName){
    [XDGSDK reportWithServerId:serverId.GetNSString() roleId:roleId.GetNSString() roleName:roleName.GetNSString()];
    NSLog(@"点击了 Report %@", serverId.GetNSString());
}

void XDGCommonIOS::StoreReview(){
    [XDGSDK storeReview];
    NSLog(@"点击 StoreReview");
}

void XDGCommonIOS::ShareFlavors(int32 type, FString uri, FString message){
    NSLog(@"点击 ShareFlavors %@", uri.GetNSString());

    dispatch_async(dispatch_get_main_queue(), ^{
        XDGShareType shareType = XDGShareTypeFacebook;//0
        if(type == 1){
            shareType = XDGShareTypeFacebook;
        }else if(type == 2){
            shareType = XDGShareTypeFacebook;
        }

        [XDGShare shareWithType:shareType url:uri.GetNSString() message:message.GetNSString() completeHandler:^(NSError * _Nullable error, BOOL cancel) {
            [XDGUE4CommonTool shareWithResult:error cancel:cancel];
        }];   
    });
}

void XDGCommonIOS::ShareImage(int32 type, FString imagePath){
    dispatch_async(dispatch_get_main_queue(), ^{
        XDGShareType shareType = XDGShareTypeFacebook;//0
        if(type == 1){
            shareType = XDGShareTypeFacebook;
        }else if(type == 2){
            shareType = XDGShareTypeFacebook;
        }

        //正式代码
        // NSData *imageData = [NSData dataWithContentsOfFile:imagePath.GetNSString()];
        // UIImage *image = [[UIImage alloc] initWithData:imageData];

        //测试代码
        NSString* filePath = [[NSBundle mainBundle] pathForResource:@"share" ofType:@"jpg"];
        UIImage* image = [UIImage imageWithContentsOfFile:filePath];
        NSLog(@"点击 ShareFlavors %@", filePath);

        if (!image) {
            NSError *error = [NSError errorWithDomain:@"com.tdsglobal.share" code:-1 userInfo:@{NSLocalizedDescriptionKey:[NSString stringWithFormat: @"can not find image with path:%@",imagePath.GetNSString()]}];
            [XDGUE4CommonTool shareWithResult:error cancel:NO];
            NSLog(@"分享图片失败");
            return;
        }
        [XDGShare shareWithType:shareType image:image completeHandler:^(NSError * _Nullable error, BOOL cancel) {
            [XDGUE4CommonTool shareWithResult:error cancel:cancel];
        }];
    });
}

void XDGCommonIOS::TrackUser(FString userId){
    [XDGTrackerManager trackUser:userId.GetNSString()];
    NSLog(@"点击 TrackUser %@", userId.GetNSString());
}

void XDGCommonIOS::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){
    [XDGTrackerManager trackRoleWithRoleId:roleId.GetNSString() roleName:roleName.GetNSString() serverId:serverId.GetNSString() level:(NSInteger)level];
    NSLog(@"点击 TrackRole %@", roleId.GetNSString());
}

void XDGCommonIOS::TrackEvent(FString eventName){
    [XDGTrackerManager trackEvent:eventName.GetNSString()];
    NSLog(@"点击 TrackEvent %@", eventName.GetNSString());
}

void XDGCommonIOS::TrackAchievement(){
    [XDGTrackerManager trackAchievement];
     NSLog(@"点击 TrackAchievement");
}

void XDGCommonIOS::EventCompletedTutorial(){
    [XDGTrackerManager eventCompletedTutorial];
     NSLog(@"点击 EventCompletedTutorial");
}

void XDGCommonIOS::EventCreateRole(){
    [XDGTrackerManager eventCreateRole];
     NSLog(@"点击 EventCreateRole");
}

void XDGCommonIOS::SetCurrentUserPushServiceEnable(bool enable){
    dispatch_async(dispatch_get_main_queue(), ^{
        [XDGMessageManager setCurrentUserPushServiceEnable:enable];
         NSLog(@"点击 PushServiceEnable %d", enable);
    });
}

bool XDGCommonIOS::IsCurrentUserPushServiceEnable(){
    bool isEnable = false;
    isEnable = [XDGMessageManager isCurrentUserPushServiceEnable];
    NSLog(@"是否开通通知了 %d", isEnable);
    return isEnable;
}


//-------ios 源代码-------
@implementation XDGUE4CommonTool

 //0成功，1取消，2失败
+ (void)shareWithResult:(NSError *)error cancel:(BOOL)cancel {
    if(error != nil){
        FXDGCommonModule::OnXDGSDKShareCompleted.Broadcast(2);
    }else if(cancel){
        FXDGCommonModule::OnXDGSDKShareCompleted.Broadcast(1);
    }else{
        FXDGCommonModule::OnXDGSDKShareCompleted.Broadcast(0);
    }
}

@end

#endif