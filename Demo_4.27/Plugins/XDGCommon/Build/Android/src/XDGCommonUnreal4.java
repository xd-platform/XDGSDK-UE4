package com.xd;

import com.xd.intl.common.XDGSDK;

import android.content.res.Configuration;
import android.util.DisplayMetrics;
import android.util.Log;
import android.app.Activity;
import android.view.Display;
import android.view.View;
import android.widget.Toast;

import android.Manifest;
import android.app.Activity;
import android.graphics.Bitmap;
import android.text.TextUtils;
import android.util.Log;

import com.tds.common.bridge.Bridge;
import com.tds.common.bridge.utils.BridgeJsonHelper;
import com.tds.common.permission.RequestPermissionCallback;
import com.tds.common.permission.TdsPermission;
import com.tds.common.widgets.image.ImageTarget;
import com.tds.common.widgets.image.TdsImage;
import com.xd.intl.common.component.share.XDGShareCallback;
import com.xd.intl.common.XDGSDK;
import com.xd.intl.common.callback.XDGInitCallback;
import com.xd.intl.common.global.GlobalLocalConfig;

import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class XDGCommonUnreal4{

    private static int width = -1;
    private static int height = -1;
    public static int orientation = -1;

    public static void initSDK(final Activity gameActivity){
        print("点击初始化");

        if (!XDGSDK.isInitialized()) {
            XDGSDK.initSDK(gameActivity, success -> {
                nativeOnXDGSDKInitSucceed(success);
            });
        }
    }


    public static boolean isInitialized(){
        print("点击是否初始化");
        return XDGSDK.isInitialized();
    }


    public static void setLanguage(int languageType){
        print("点击设置语言:" + languageType);
        XDGSDK.setLanguage(languageType);
    }


    public static void report(String serverId, String roleId, String roleName){
        print("点击report");
        XDGSDK.report(serverId, roleId, roleName);
    }


    public static void trackUser(String userId){
        print("点击trackUser");
        XDGSDK.trackUser(userId);
    }


    public static void trackRole(String serverId,
                                    String roleId,
                                    String roleName,
                                    int level){
            print("点击trackRole");
            XDGSDK.trackRole(serverId, roleId, roleName, level);
        }


    public static void trackEvent(String eventName){
        print("点击trackEvent");
        XDGSDK.trackEvent(eventName);
    }


    public static void trackAchievement(){
        print("点击 trackAchievement");
        XDGSDK.trackAchievement();
    }

    public static String getSDKVersionName(){
        print("点击 getSDKVersionName");
        return XDGSDK.getVersionName();
    }


    public static void shareFlavors(int shareFlavors,
                            String uri,
                            String message){
        print("点击 share 3个参数");
        XDGSDK.share(shareFlavors, uri, message, new XDGShareCallback() {
            @Override
            public void shareSuccess() {
                nativeOnXDGSDKShareCompleted(0);
            }

            @Override
            public void shareCancel() {
                nativeOnXDGSDKShareCompleted(1);
            }

            @Override
            public void shareFailed(String error) {
                nativeOnXDGSDKShareCompleted(2);
            }
        });
    }


    public static void shareImage(int shareFlavors,
                                String imagePath){
                    print("点击 share 2个参数");
                    
                    TdsPermission.with(Bridge.getInstance().getActivity())
                    .permission(Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.READ_EXTERNAL_STORAGE)
                    .request(new RequestPermissionCallback() {
                        @Override
                        public void onResult(boolean allGranted, List<String> grantList, List<String> denList) {
                            if (allGranted) {
                                TdsImage.get(Bridge.getInstance().getActivity()).load(new File(imagePath))
                                        .into(new ImageTarget() {
                                            @Override
                                            public void onSuccess(Bitmap bitmap) {
                                                XDGSDK.share(shareFlavors, bitmap, new XDGShareCallback() {
                                                    @Override
                                                    public void shareSuccess() {
                                                        nativeOnXDGSDKShareCompleted(0);
                                                    }

                                                    @Override
                                                    public void shareCancel() {
                                                        nativeOnXDGSDKShareCompleted(1);
                                                    }

                                                    @Override
                                                    public void shareFailed(String error) {
                                                        nativeOnXDGSDKShareCompleted(2);
                                                    }
                                                });
                                            }

                                            @Override
                                            public void onFailure(Throwable throwable) {
                                                        nativeOnXDGSDKShareCompleted(2);
                                            }
                                        });
                            } else {
                                nativeOnXDGSDKShareCompleted(2);
                            }
                        }
                    });
        }


    public static void storeReview(){
        print("点击 storeReview");
        XDGSDK.storeReview();
    }


    public static void setCurrentUserPushServiceEnable(boolean enable){
        print("点击 setCurrentUserPushServiceEnable");
        XDGSDK.setCurrentUserPushServiceEnable(enable);
    }


    public static boolean isCurrentUserPushServiceEnable(){
        print("点击 isCurrentUserPushServiceEnable");
        return XDGSDK.isCurrentUserPushServiceEnable();
    }


    public static void eventCompletedTutorial(){
        print("点击 eventCompletedTutorial");

    }


    public static void eventCreateRole(){
         print("点击 eventCreateRole");
        
    }

    // 下面是与SDK无关方法
    public static void onCreate(final Activity activity) {
        Display display = activity.getWindowManager().getDefaultDisplay();
        DisplayMetrics dm = new DisplayMetrics();
        display.getRealMetrics(dm);

        if(activity.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE){
            width = dm.widthPixels;
            height = dm.heightPixels;
        }
    }

    public static void onStop(final Activity activity) {

    }

    public static void onResume(View ueContainerView, final Activity activity) {
        if(width <= 0 || height <= 0 || width < height){
            return;
        }
        ueContainerView.getLayoutParams().width = width;
        ueContainerView.getLayoutParams().height = height;
    }

    private static void print(String msg){
        Log.e(" ====== sdk log ====== ", msg);
    }


    //------JNI 回调-------
    public native static void nativeOnXDGSDKInitSucceed(boolean success);

    //0成功，1取消，2失败
    public native static void nativeOnXDGSDKShareCompleted(int code);

}