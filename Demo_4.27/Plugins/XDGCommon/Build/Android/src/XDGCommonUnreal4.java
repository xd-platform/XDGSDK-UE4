package com.xd;

import com.xd.intl.common.XDGSDK;
import android.net.Uri;
import com.xd.intl.common.component.share.XDGShareType;
import android.content.res.Configuration;
import android.util.DisplayMetrics;
import android.util.Log;
import android.app.Activity;
import android.view.Display;
import android.view.View;
import android.widget.Toast;
import android.os.Handler;
import android.os.Looper;

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
import com.xd.intl.common.bean.XDGRegionInfo;

import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import com.xd.intl.common.utils.EnvHelper;



public class XDGCommonUnreal4 {

    private static int width = -1;
    private static int height = -1;
    public static int orientation = -1;
    public static Activity tmpActivity;

    public static void initSDK(final Activity gameActivity) {
        print("点击初始化");

        if (!XDGSDK.isInitialized()) {
            // 要在主线程执行
            new Handler(Looper.getMainLooper()).post(new Runnable() {
                @Override
                public void run() {

                    XDGSDK.initSDK(gameActivity, new XDGInitCallback() {
                        @Override
                        public void initCallback(boolean success, String message) {
                            Map<String, Object> params = new HashMap<>();
                            params.put("success", success);
                            params.put("configInfo", GlobalLocalConfig.INSTANCE.getGlobalLocalConfigInfo());
                            if (success) {
                                params.put("message", "init success");
                            } else {
                                params.put("message", message);
                            }
                            String result = BridgeJsonHelper.object2JsonString(params);
                            nativeOnXDGSDKInitSucceed(success, result);
                        }
                    });

                }
            });
        }

        //测试代码---start
          tmpActivity = gameActivity;
        //测试代码---end
    }

    public static boolean isInitialized() {
        boolean isInit = XDGSDK.isInitialized();
        print("点击是否初始化: " + isInit);
        return isInit;
    }

    public static void setLanguage(int languageType) {
        print("点击设置语言:" + languageType);
        XDGSDK.setLanguage(languageType);
    }

    public static void report(String serverId, String roleId, String roleName) {
        print("点击 report:" + serverId + " roleId:" + roleId + " roleName:" + roleName);
        XDGSDK.report(serverId, roleId, roleName);
    }

    public static void trackUser(String userId) {
        print("点击trackUser");
        XDGSDK.trackUser(userId);
    }

    public static void trackRole(String serverId,
            String roleId,
            String roleName,
            int level) {
        print("点击 trackUser:" + serverId + " roleId:" + roleId + " roleName:" + roleName + " level:" + level);
        XDGSDK.trackRole(serverId, roleId, roleName, level);
    }

    public static void trackEvent(String eventName) {
        print("点击trackEvent" + eventName);
        XDGSDK.trackEvent(eventName);
    }

    public static void trackAchievement() {
        print("点击 trackAchievement");
        XDGSDK.trackAchievement();
    }

    public static String getSDKVersionName() {
        String v = XDGSDK.getVersionName();
        print("点击 getSDKVersionName: " + v);
        return v;
    }

    public static void shareFlavors(int shareFlavors,
            String uri,
            String message) {
        print("点击 share:" + shareFlavors + " uri:" + uri + " message:" + message);

        // 要在主线程执行
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {

                @XDGShareType.Type
                int type = XDGShareType.FACEBOOK;
                if (shareFlavors == 1) {
                    type = XDGShareType.LINE;
                } else if (shareFlavors == 2) {
                    type = XDGShareType.TWITTER;
                }

                XDGSDK.share(type, uri, message, new XDGShareCallback() {
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
        });
    }

    public static void shareImage(int shareFlavors,
            String imagePath) { // 安卓uri path string
        print("点击 share 2个参数 shareFlavors：" + shareFlavors + "  imagePath: " + imagePath);

        // 要在主线程执行
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {

                @XDGShareType.Type
                int type = XDGShareType.FACEBOOK;
                if (shareFlavors == 1) {
                    type = XDGShareType.LINE;
                } else if (shareFlavors == 2) {
                    type = XDGShareType.TWITTER;
                }

                if (type == XDGShareType.FACEBOOK) {
                    try {
                        File file = new File(imagePath);
                        if (file.exists()) {
                            Bitmap bitmap = BitmapFactory.decodeFile(imagePath);
                            XDGSDK.share(type, bitmap, new XDGShareCallback() {
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
                    } catch (Exception e) {
                        e.printStackTrace();
                        nativeOnXDGSDKShareCompleted(2);
                    }

                } else {
                    Uri uri = Uri.parse(new File(imagePath).toString());
                    XDGSDK.share(type, uri, new XDGShareCallback() {
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
            }
        });
    }

    public static void storeReview() {
        print("点击 storeReview");
        XDGSDK.storeReview();
    }

    public static void setCurrentUserPushServiceEnable(boolean enable) {
        print("点击 setCurrentUserPushServiceEnable " + enable);
        XDGSDK.setCurrentUserPushServiceEnable(enable);
    }

    public static boolean isCurrentUserPushServiceEnable() {
        boolean r = XDGSDK.isCurrentUserPushServiceEnable();
        print("点击 isCurrentUserPushServiceEnable" + r);
        return r;
    }

    public static void eventCompletedTutorial() {
        print("点击 eventCompletedTutorial");
        XDGSDK.eventCompletedTutorial();
    }

    public static void eventCreateRole() {
        print("点击 eventCreateRole");
        XDGSDK.eventCreateRole();
    }

    public static void getRegionInfo() {
        XDGRegionInfo info = XDGSDK.getRegionInfo();
        nativeOnXDGSDKGetRegionInfoCompleted(info.countryCode, info.city, info.timeZone, info.locationInfoType);
    }


    public static void developUrlInit(final Activity activity) {
        //测试代码--start
        EnvHelper.setApiEnv(EnvHelper.EnvEnum.Dev); //设置测试环境
        initSDK(activity);
        //测试代码--end
    }


    // 下面是与SDK无关方法
    public static void onCreate(final Activity activity) {
        Display display = activity.getWindowManager().getDefaultDisplay();
        DisplayMetrics dm = new DisplayMetrics();
        display.getRealMetrics(dm);

        if (activity.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
            width = dm.widthPixels;
            height = dm.heightPixels;
        }
    }

    public static void onStop(final Activity activity) {

    }

    public static void onResume(View ueContainerView, final Activity activity) {
        if (width <= 0 || height <= 0 || width < height) {
            return;
        }
        ueContainerView.getLayoutParams().width = width;
        ueContainerView.getLayoutParams().height = height;
    }

    private static void print(String msg) {
        Log.i(" ====== sdk log Common ====== ", msg);
    }

    // ------JNI 回调-------
    public native static void nativeOnXDGSDKInitSucceed(boolean success, String result);

    // 0成功，1取消，2失败
    public native static void nativeOnXDGSDKShareCompleted(int code);

    public native static void nativeOnXDGSDKGetRegionInfoCompleted(String countryCode, String city, String timeZone,
            String locationInfoType);

}