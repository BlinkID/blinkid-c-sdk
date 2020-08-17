package com.microblink.recognizerApi;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.io.IOException;
import java.io.InputStream;

import androidx.test.InstrumentationRegistry;
import androidx.test.core.app.ApplicationProvider;
import androidx.test.ext.junit.runners.AndroidJUnit4;

import static org.junit.Assert.*;

@RunWith(AndroidJUnit4.class)
public class IdRecognizerTest {

    @Test
    public void processImage() {
        // load image from test assets
        AssetManager am = InstrumentationRegistry.getContext().getAssets();
        InputStream is = null;
        Bitmap image = null;
        try {
            is = am.open("id.jpg");
            image = BitmapFactory.decodeStream(is);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if ( is != null ) {
                try {
                    is.close();
                } catch (IOException ignored) { }
            }
        }

        assertNotNull(image);

        IdRecognizer idRecognizer = new IdRecognizer(ApplicationProvider.getApplicationContext());

        String result = idRecognizer.processBitmap(image);

        assertEquals( "SAMPLE", result );
    }
}