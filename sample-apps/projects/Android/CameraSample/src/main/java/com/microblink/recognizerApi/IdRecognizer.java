package com.microblink.recognizerApi;

import android.content.Context;
import android.graphics.Bitmap;

public class IdRecognizer {
    static {
        System.loadLibrary("RecognizerApi");
        System.loadLibrary("jni");
    }

    private long mNativeContext = 0;

    public IdRecognizer(Context applicationContext) {
        initializeApplication(applicationContext);
        mNativeContext = nativeConstruct();
    }

    public String processVideoFrame(byte[] image, int width, int height) {
        return nativeProcessVideoFrame(mNativeContext, image, width, height);
    }

    public void resetRecognizer() {
        nativeResetRecognizer(mNativeContext);
    }

    public String processBitmap(Bitmap bitmap) {
        return nativeProcessBitmap(mNativeContext, bitmap);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeTerminate(mNativeContext);
    }

    private static native void initializeApplication(Context applicationContext);

    private static native long nativeConstruct();
    private static native void nativeTerminate(long nativeContext);
    private static native String nativeProcessVideoFrame(long nativeContext, byte[] image, int width, int height);
    private static native void nativeResetRecognizer(long nativeContext);
    private static native String nativeProcessBitmap(long nativeContext, Bitmap bitmap);
}
