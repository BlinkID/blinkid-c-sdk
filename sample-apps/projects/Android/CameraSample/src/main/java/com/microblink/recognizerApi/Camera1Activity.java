package com.microblink.recognizerApi;

import android.Manifest;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.graphics.ImageFormat;
import android.hardware.Camera;
import android.os.Bundle;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@SuppressWarnings("deprecation")
public class Camera1Activity extends Activity implements SurfaceHolder.Callback, Camera.PreviewCallback {

    private static final int PERMISSION_REQUEST_CODE = 235;

    private final static String TAG = "Camera1Activity";

    private SurfaceView mSurfaceView;
    private Camera mCamera;
    private boolean mHaveSurfaceView = false;
    private byte[] mPixelBuffer;
    private int mFrameWidth;
    private int mFrameHeight;

    private boolean mHasCameraPermission = false;
    private boolean mRecognitionPaused = true;

    private IdRecognizer mIdRecognizer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera1);

        // initialize native code with application context
        mIdRecognizer = new IdRecognizer(this.getApplicationContext());

        // setup camera view
        mSurfaceView = findViewById(R.id.camera1SurfaceView);

        // Request permissions if not granted, we need CAMERA permission and
        // WRITE_EXTERNAL_STORAGE permission because images that are taken by camera
        // will be stored on external storage and used in recognition process
        List<String> requiredPermissions = new ArrayList<>();
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
            requiredPermissions.add(Manifest.permission.CAMERA);
        } else {
            mHasCameraPermission = true;
        }

        if (requiredPermissions.size() > 0) {
            String[] permArray = new String[requiredPermissions.size()];
            permArray = requiredPermissions.toArray(permArray);
            ActivityCompat.requestPermissions(this, permArray, PERMISSION_REQUEST_CODE);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        for (int grantResult : grantResults) {
            if (grantResult != PackageManager.PERMISSION_GRANTED) {
                new AlertDialog.Builder(this)
                        .setTitle("Exiting")
                        .setMessage("Exiting app, camera permission not granted.")
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                finish();
                            }
                        })
                        .setCancelable(false)
                        .create()
                        .show();
                return;
            } else {
                if ( mHaveSurfaceView ) {
                    startCamera();
                }
            }
        }
    }

    @Override
    protected void onStart() {
        super.onStart();

        mSurfaceView.getHolder().addCallback(this);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (mHaveSurfaceView && mHasCameraPermission) {
            startCamera();
        }

    }

    private void startCamera() {
        try {
            mCamera = Camera.open();
            Camera.Parameters params = mCamera.getParameters();
            List<String> supportedFocusModes = params.getSupportedFocusModes();
            if (supportedFocusModes.contains(Camera.Parameters.FOCUS_MODE_CONTINUOUS_PICTURE)) {
                params.setFocusMode(Camera.Parameters.FOCUS_MODE_CONTINUOUS_PICTURE);
            } else {
                params.setFocusMode(Camera.Parameters.FOCUS_MODE_AUTO);
            }

            List<Camera.Size> sizes = params.getSupportedPreviewSizes();
            Camera.Size bestSize = null;
            int bestDiff = Integer.MAX_VALUE;
            for (Camera.Size size : sizes) {
                int diff = size.width * size.height - 1920 * 1080;
                if (Math.abs(diff) < Math.abs(bestDiff)) {
                    bestDiff = diff;
                    bestSize = size;
                }
            }
            params.setPreviewFormat(ImageFormat.NV21);
            params.setPreviewSize(bestSize.width, bestSize.height);
            mFrameWidth = bestSize.width;
            mFrameHeight = bestSize.height;

            mCamera.setParameters(params);

            mPixelBuffer = new byte[bestSize.width * bestSize.height * ImageFormat.getBitsPerPixel(ImageFormat.NV21) / 8];
            mCamera.addCallbackBuffer(mPixelBuffer);
            mCamera.setPreviewCallbackWithBuffer(this);

            mCamera.setPreviewDisplay(mSurfaceView.getHolder());
            mCamera.setDisplayOrientation(90);

            mCamera.startPreview();

            mRecognitionPaused = false;

        } catch (RuntimeException exc) {
            Log.e(TAG, "Failed to open camera", exc);
            finish();
        } catch (IOException e) {
            Log.e(TAG, "Failed to set preview display!", e);
            finish();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (mCamera != null) {

            mRecognitionPaused = true;

            mCamera.stopPreview();
            mCamera.release();
            mCamera = null;
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
        mSurfaceView.getHolder().removeCallback(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        mHaveSurfaceView = true;
        if ( mHasCameraPermission ) {
            startCamera();
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        mHaveSurfaceView = false;
    }

    @Override
    public void onPreviewFrame(byte[] data, Camera camera) {
        if ( !mRecognitionPaused ) {
            String result = mIdRecognizer.processVideoFrame(data, mFrameWidth, mFrameHeight);

            if ( result != null ) {
                mRecognitionPaused = true;
                // display alert dialog with result
                new AlertDialog.Builder(this)
                        .setTitle("Result")
                        .setMessage("Hello, " + result + "!")
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                mIdRecognizer.resetRecognizer();
                                mRecognitionPaused = false;
                            }
                        })
                        .setCancelable(false)
                        .create()
                        .show();
            }
        }
        camera.addCallbackBuffer(data);
    }
}
