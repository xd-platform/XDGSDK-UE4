package com.xd;

import android.text.TextUtils;
import android.util.Log;
import android.os.Handler;
import android.os.Looper;

import com.taptap.reactor.rxandroid.schedulers.AndroidSchedulers;
import com.taptap.reactor.schedulers.Schedulers;
import com.tds.common.bridge.BridgeCallback;
import com.tds.common.bridge.utils.BridgeJsonHelper;

import com.xd.intl.account.XDGAccount;
import com.xd.intl.account.entity.TapSessionToken;
import com.xd.intl.account.impl.TDSGlobalAccountComponent;
import com.xd.intl.account.utils.LoginEntriesHelper;
import com.xd.intl.common.base.AbstractSubscriber;
import com.xd.intl.common.base.XDGError;
import com.xd.intl.common.bean.XDGUser;
import com.xd.intl.common.callback.Callback;
import com.xd.intl.common.callback.XDGUserStatusChangeCallback;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class XDGAccountUnreal4{

    private static long lastClick = 0; //防止重复点击
    private static int gapTime = 1000; //点击间隔毫秒

    public static void login(){
        if (System.currentTimeMillis() - lastClick > gapTime) {
            print("点击 Login");
            lastClick = System.currentTimeMillis();
            XDGAccount.login(new Callback<XDGUser>() {
                @Override
                public void onCallback(XDGUser tdsGlobalUser, XDGError tdsServerError) {
                constructorUserForBridge(tdsGlobalUser, tdsServerError, true);
                }
            });   
         }
    }

     private static void constructorUserForBridge(XDGUser xdgUser, XDGError tdsServerError, boolean isLogin) {
        if (xdgUser != null) {
            Map<String, Object> tdsUserParams = new HashMap<>(4);
            tdsUserParams.put("userId", xdgUser.getId());
            tdsUserParams.put("name", xdgUser.getName());
            tdsUserParams.put("loginType", LoginEntriesHelper.getLoginEntryTypeByType(xdgUser.getLoginType()).getName());
            List<String> boundAccounts;
            if (xdgUser.getBoundAccounts() == null) {
                boundAccounts = new ArrayList<String>();
            } else {
                boundAccounts = xdgUser.getBoundAccounts();
            }
            tdsUserParams.put("boundAccounts", boundAccounts);
            Map<String, Object> tokenParams = new HashMap<>(5);
            tokenParams.put("kid", xdgUser.getAccessToken().getKid());
            tokenParams.put("tokenType", xdgUser.getAccessToken().getTokenType());
            tokenParams.put("macKey", xdgUser.getAccessToken().getMacKey());
            tokenParams.put("macAlgorithm", xdgUser.getAccessToken().getMacAlgorithm());
            tdsUserParams.put("token", tokenParams);

            String userJson = BridgeJsonHelper.object2JsonString(tdsUserParams);
            if(isLogin){ //登录成功
                nativeOnXDGSDKLoginSucceed(userJson);
            }else{//获取用户成功
                nativeOnXDGSDKGetUserSucceed(userJson);
            }

            print("成功：" + userJson);

        }else if (tdsServerError != null) {
            int code  = tdsServerError.getCode();
            String msg = tdsServerError.getMessage();

            if(isLogin){ //登录失败
                nativeOnXDGSDKLoginFailed(code, msg);
            }else{//获取用户失败
                nativeOnXDGSDKGetUserFailed(code, msg);
            }

            print("失败：code = " + code + "  msg = " + msg);
        }
    }
	
    public static void loginByType(String loginType){
         if (System.currentTimeMillis() - lastClick > gapTime) {
            print("点击  LoginByType");
            lastClick = System.currentTimeMillis();
            new Handler(Looper.getMainLooper()).post(new Runnable() {
                @Override
                public void run() {
                    if (!TextUtils.isEmpty(loginType)) {
                        XDGAccount.loginByType(LoginEntriesHelper.getLoginTypeForLogin(loginType), new Callback<XDGUser>() {
                            @Override
                            public void onCallback(XDGUser user, XDGError tdsServerError) {
                                constructorUserForBridge(user, tdsServerError, true);
                            }
                        });
                    }
                }
            });
         }
    }
	
    public static void addUserStatusChangeCallback(){
        print("点击  AddUserStatusChangeCallback");

         XDGAccount.addUserStatusChangeCallback(new XDGUserStatusChangeCallback() {
            @Override
            public void userStatusChange(int code, String message) {
                 nativeOnXDGSDKUserStateChanged(code, message);
                 print("changed status, code = " + code + "  msg = " + message);
            }
        });
    }
    
    public static void getUser(){
        print("点击  GetUser");
         XDGAccount.getUser(new Callback<XDGUser>() {
            @Override
            public void onCallback(XDGUser user, XDGError tdsServerError) {
                constructorUserForBridge(user, tdsServerError, false);
            }
        });
    }
	
    public static void openUserCenter(){
        print("点击  OpenUserCenter");
         XDGAccount.openUserCenter();
    }
	
    public static void logout(){
        print("点击  Logout");
        XDGAccount.logout();
    }
	
    public static void loginSync(){
        print("点击  LoginSync");

        Callback<TapSessionToken> internalCallback = (tapSessionToken, tdsServerError) -> {
            String sessionToken = "";
            if (tapSessionToken != null) {
               sessionToken = tapSessionToken.sessionToken;
            }
            nativeOnXDGSDKLoginSync(sessionToken);
            print("token为: " + sessionToken);
        };
        TDSGlobalAccountComponent.INSTANCE.connectTDSServer()
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(new AbstractSubscriber<>(internalCallback));
    }

    private static void print(String msg){
        Log.e(" ====== sdk log ====== ", msg);
    }

     //------JNI 回调-------
    public native static void nativeOnXDGSDKLoginSucceed(String userJson);

    public native static void nativeOnXDGSDKLoginFailed(int code, String msg);

    public native static void nativeOnXDGSDKGetUserSucceed(String userJson);

    public native static void nativeOnXDGSDKGetUserFailed(int code, String msg);

    public native static void nativeOnXDGSDKUserStateChanged(int code, String msg);

    public native static void nativeOnXDGSDKLoginSync(String sessionToken);

}