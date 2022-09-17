adb push ./Install/libs/libMylog.so /data/local/tmp
adb push ./Install/libs/main /data/local/tmp
adb shell "cd /data/local/tmp && chmod 777 main &&./main"