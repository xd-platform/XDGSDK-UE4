## XDGSDK-UE4配置

#### 1.添加Plugins文件夹里的插件
![plugins](./Demo_4.27/image/plugins.png)

#### 2.配置Bootstrap数据
如果看不到该配置，请重启UE4开发工具。在项目中添加 `SampleDynamicProperties.h`  和 `SampleDynamicProperties.c++` 读取配置信息。
![boot](./Demo_4.27/image/boot.png)


#### 3.配置iOS数据
把 `XDGCommon/Source/XDGCommon/iOS/iOSConfigs` 文件夹里的 `GoogleService-Info.plist` 和 `XDG-Info.plist` 配置成自己的文件。

把 `XDGCommon/Source/XDGCommon/XDGCommon_iOS_UPL.xml` 里的 `CFBundleURLSchemes`值配置成自己的参数。

#### 4.配置Android数据
把 `XDGCommon/Source/XDGCommon/Android/assets` 文件夹里的  `XDG_info.json`  
和 `XDGAccount/Source/XDGAccount/Android/googleJson` 文件夹里的 `google-services.json` 配置成自己的文件。

把`XDGCommon/Source/XDGCommon/XDGCommon_Android_UPL.xml` 中 `addElements`里的参数配置成自己的。



## XDGCommon 使用

#### 1.使用接口在 `XDGCommon/Source/XDGCommon/Public/XDGCommonBPLibrary.h` 中

```
//初始化SDK
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void InitSDK();

// 设置语言，int参数如下
// 0 简体中文
// 1 繁体中文
// 2 英文
// 3 泰文
// 4 印尼文
// 5 韩文
// 6 日文
// 7 德语
// 8 法语
// 9 葡萄牙语
// 10 西班牙语
// 11 土耳其语
// 12 俄语
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void SetLanguage(int32 langType);

//获取版本号
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static FString GetSDKVersionName();

//是否初始化
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static bool IsInitialized();

//打开评分
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void StoreReview();

//上报游戏信息
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void Report(FString serverId, FString roleId, FString roleName);

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

//分享
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void ShareFlavors(int32 type, FString uri, FString message);

UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void ShareImage(int32 type, FString imagePath);

//设置是否接收通知
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void SetCurrentUserPushServiceEnable(bool enable);

//是否接收通知
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static bool IsCurrentUserPushServiceEnable();

//获取位置信息
UFUNCTION(BlueprintCallable, Category = "XDGCommon")
static void GetRegionInfo();
```
#### 2.接口回调在 `XDGCommon/Source/XDGCommon/Public/XDGCommon.h` 中

```
//初始化回调
//success: true成功， false失败
UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
static FXDGSDKInitSucceed OnXDGSDKInitSucceed;

//分享回调
//code: 0成功，1取消，2失败
UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
static FXDGSDKShareCompleted OnXDGSDKShareCompleted;

//获取位置信息回调
//countryCode, city, timeZone, locationInfoType
UPROPERTY(BlueprintAssignable, Category = "XDGCommon")
static FXDGSDKGetRegionInfoCompleted OnXDGSDKGetRegionInfoCompleted;
```

#### 3. `XDGCommon`, `XDGAccount`, `XDGPayment` 的接口使用及回调可参考 `Source/Demo/DemoGameModeBase.h`  和 `Source/Demo/DemoGameModeBase.cpp`文件

`DemoGameModeBase.h`参考如下：
```
UCLASS()
class DEMO_API ADemoGameModeBase : public AGameModeBase
{
  GENERATED_BODY()
  virtual void BeginPlay() override;

  //XDGCommon
  void OnXDGSDKInitSucceed(const bool);

  //0成功，1取消，2失败
  void OnXDGSDKShareCompleted(const int32);

  void OnXDGSDKGetRegionInfoCompleted(const FString&, const FString&, const FString&, const FString&);

  //XDGAccount 
  void OnXDGSDKLoginSucceed(const FString&);

  void OnXDGSDKLoginFailed(const int32, const FString&);

  void OnXDGSDKGetUserSucceed(const FString&);

  void OnXDGSDKGetUserFailed(const int32, const FString&);

  void OnXDGSDKUserStateChanged(const int32, const FString&);

  void OnXDGSDKLoginSync(const FString&);

  //XDGPayment
  void OnXDGSDKPaymentSucceed(const FString&, const FString&, const FString&, const FString&);

  void OnXDGSDKPaymentFailed(const int32, const FString&);

  void OnXDGSDKQueryProductIdsSucceed(const FString&);

  void OnXDGSDKQueryProductIdsFailed(const int32, const FString&);

  void OnXDGSDKQueryRestoredPurchasesSucceed(const FString&);

  void OnXDGSDKQueryRestoredPurchasesFailed(const int32, const FString&);

  void OnXDGSDKPayWithWebCompleted(const FString&, const FString&, const int32, const FString&);

  void OnXDGSDKCheckRefundStatusSucceed(const FString&);

  void OnXDGSDKCheckRefundStatusFailed(const int32, const FString&);

};
```

`DemoGameModeBase.cpp`部分代码参考如下：
```
void ADemoGameModeBase::BeginPlay(){
    //XDGCommon
    FXDGCommonModule::OnXDGSDKInitSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKInitSucceed);
    FXDGCommonModule::OnXDGSDKShareCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKShareCompleted);
    FXDGCommonModule::OnXDGSDKGetRegionInfoCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetRegionInfoCompleted);

    //XDGAccount
    FXDGAccountModule::OnXDGSDKLoginSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSucceed);
    FXDGAccountModule::OnXDGSDKLoginFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginFailed);
    FXDGAccountModule::OnXDGSDKGetUserSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserSucceed);
    FXDGAccountModule::OnXDGSDKGetUserFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKGetUserFailed);
    FXDGAccountModule::OnXDGSDKUserStateChanged.AddUObject(this, &ADemoGameModeBase::OnXDGSDKUserStateChanged);
    FXDGAccountModule::OnXDGSDKLoginSync.AddUObject(this, &ADemoGameModeBase::OnXDGSDKLoginSync);

    //XDGPayment
    FXDGPaymentModule::OnXDGSDKPaymentSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentSucceed);
    FXDGPaymentModule::OnXDGSDKPaymentFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPaymentFailed);
    FXDGPaymentModule::OnXDGSDKQueryProductIdsSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsSucceed);
    FXDGPaymentModule::OnXDGSDKQueryProductIdsFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryProductIdsFailed);
    FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesSucceed);
    FXDGPaymentModule::OnXDGSDKQueryRestoredPurchasesFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKQueryRestoredPurchasesFailed);
    FXDGPaymentModule::OnXDGSDKPayWithWebCompleted.AddUObject(this, &ADemoGameModeBase::OnXDGSDKPayWithWebCompleted);
    FXDGPaymentModule::OnXDGSDKCheckRefundStatusSucceed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKCheckRefundStatusSucceed);
    FXDGPaymentModule::OnXDGSDKCheckRefundStatusFailed.AddUObject(this, &ADemoGameModeBase::OnXDGSDKCheckRefundStatusFailed);

    UE_LOG(LogTemp, Log, TEXT("playingsgm"));
}

//XDGCommon
void ADemoGameModeBase::OnXDGSDKInitSucceed(const bool success){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKInitSucceed"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKInitSucceed: " + FString::FromInt(success));
}


void ADemoGameModeBase::OnXDGSDKShareCompleted(const int32 code){
    UE_LOG(LogTemp, Log, TEXT("点击了 OnXDGSDKShareCompleted"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnXDGSDKShareCompleted: " + FString::FromInt(code));
}
...

```

## XDGAccount 使用

#### 1.接口使用位于 `XDGAccount/Source/XDGAccount/Public/XDGAccountBPLibrary.h` 中

```
//弹框登录
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void Login();

//单独调用第三方登录，可传如下字符串参数
// "TAPTAP"
// "GOOGLE"
// "FACEBOOK"
// "APPLE"
// "LINE"
// "TWITTER"
// "GUEST"
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void LoginByType(FString loginType);

//绑定状态回调（登出，解绑等）
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void AddUserStatusChangeCallback();

//获取用户
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void GetUser();

//打开用户中心
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void OpenUserCenter();

//退出
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void Logout();

//获取sessionToken
UFUNCTION(BlueprintCallable, Category = "XDGAccount")
static void LoginSync();
```

#### 2. 接口回调位于 `XDGAccount/Source/XDGAccount/Public/XDGAccount.h` 中

```
//登录成功
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKLoginSucceed OnXDGSDKLoginSucceed;

//登录失败
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKLoginFailed OnXDGSDKLoginFailed;

//获取用户成功
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKGetUserSucceed OnXDGSDKGetUserSucceed;

//获取用户失败
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKGetUserFailed OnXDGSDKGetUserFailed;

//用户状态回调
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKUserStateChanged OnXDGSDKUserStateChanged;

//sessionToken 回调
UPROPERTY(BlueprintAssignable, Category = "XDGAccount")
static FXDGSDKLoginSync OnXDGSDKLoginSync;
```

## XDGPayment 使用
## 由于支付模块iOS和安卓差别比较大，接口及回调数据需要区分平台分别接入！

接口使用位于 `XDGPayment/Source/XDGPayment/Public/XDGPaymentBPLibrary.h` 中

接口回调位于 `XDGPayment/Source/XDGPayment/Public/XDGPayment.h` 中

#### 1.接口使用

```
//下面是ios 安卓都有的方法（5个）
UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void QueryWithProductIdArray(TArray<FString> productIds);

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void PayWithProduct(FString orderId,
							FString productId,
							FString roleId,
							FString serverId,
							FString ext);

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void QueryRestoredPurchases();

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void CheckRefundStatus();

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void CheckRefundStatusWithUI();

//-------------------------------------------------------------

//下面是安卓独有方法(3个)
UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void RestorePurchase(FString purchaseToken,
							FString productId,
							FString orderId,
							FString roleId,
							FString serverId,
							FString ext);

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void PayWithWeb(FString serverId,
						FString roleId);

UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void PayWithChannel(FString orderId,
							FString productId,
							FString roleId,
							FString serverId,
							FString ext);

//-------------------------------------------------------------

//下面是iOS独有方法(1个)
UFUNCTION(BlueprintCallable, Category = "XDGPayment")
static void PurchaseToken(FString transactionIdentifier,
							FString productIdentifier,
							FString orderId,
							FString roleId,
							FString serverId,
							FString ext);
```

#### 2. 接口回调

```
//支付成功
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKPaymentSucceed OnXDGSDKPaymentSucceed;

//支付失败
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKPaymentFailed OnXDGSDKPaymentFailed;

//查询产品成功
//products数组json, 注意数组里ios和安卓的对象字段不一样的！
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKQueryProductIdsSucceed OnXDGSDKQueryProductIdsSucceed;

//查询产品失败
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKQueryProductIdsFailed OnXDGSDKQueryProductIdsFailed;

//transactions数组json, 注意数组里ios和安卓的对象字段不一样的！
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKQueryRestoredPurchasesSucceed OnXDGSDKQueryRestoredPurchasesSucceed;

UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKQueryRestoredPurchasesFailed OnXDGSDKQueryRestoredPurchasesFailed;

//网页支付回调
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKPayWithWebCompleted OnXDGSDKPayWithWebCompleted;

//检查补款成功
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKCheckRefundStatusSucceed OnXDGSDKCheckRefundStatusSucceed;

//检查补款失败
UPROPERTY(BlueprintAssignable, Category = "XDGPayment")
static FXDGSDKCheckRefundStatusFailed OnXDGSDKCheckRefundStatusFailed;
```





