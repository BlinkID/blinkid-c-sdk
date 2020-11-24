/**
* Copyright (c) Microblink Ltd. All rights reserved.
*
* ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
* OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
* WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
* UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
* THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
* REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
*/

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
