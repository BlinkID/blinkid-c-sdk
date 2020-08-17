# BlinkID C SDK

_BlinkID C SDK_ enables scanning various identity documents including driving licenses, national identity cards, passports and others. SDK includes:

- Real-time data extraction
- Offline, on-device processing for maximum security
- Front and back side data capture and comparison
- Extraction of face, document, and signature photo

Integrating _BlinkID C SDK_ into your app requires experience with native development with the C language. If you are looking for native or specific cross-platform SDKs with built-in UX and camera management, please go to the [BlinkID Github page](https://github.com/BlinkID). If you want to use BlinkID as a backend service on your Linux servers, please go [here](https://github.com/microblink/docker).

You should use _BlinkID C SDK_ if you are developing:

- Linux or macOS desktop applications
- Custom hardware that runs a Linux-based OS on an Intel-compatible CPU, such as airport document readers and ATM machines
- C++. Java, Python or Ruby applications (you wrap the C-API in your target language)
- Server-side solutions where quick runtime is essential and a docker-based integration cannot meet your performance or compliance needs
- mobile apps that run on native code and need to work without the extra overhead incurred by Objective C (iOS) or Java (Android) callbacks

# Table of contents

* [System requirements](#system-requirements)
    * [Minimum hardware requirements](#hw-requirements)
    * [Minimum software requirements](#sw-requirements)
* [Integration instructions](#integration)
    * [Package contents](#pkg-contents)
    * [Configuring your build system](#configure-build)
        * [Linux](#configure-linux)
        * [MacOS](#configure-macos)
        * [Android](#configure-android)
        * [iOS](#configure-ios)
    * [Obtaining a license key](#obtaining-a-license-key)
    * [Performing your first scan](#first-scan)
* [The `Recognizer` concept and the `RecognizerRunner`](#available-recognizers)
    * [The `Recognizer` concept](#recognizer-concept)
    * [`RecognizerRunner`](#recognizer-runner)
* [Handling processing events with `RecognitionCallback`](#recognition-callbacks)
* [List of available recognizers](#recognizer-list)
    * [ID barcode recognizer](#idBarcodeRecognizer)
    * [BlinkID recognizer](#blinkidRecognizer)
    * [BlinkID combined recognizer](#blinkidCombinedRecognizer)
* [Troubleshooting](#troubleshoot)
    * [Integration problems](#integration-problems)
    * [Licensing problems](#licensing-problems)
        * [Other problems](#other-problems)
* [FAQ and known issues](#faq)
    * [Android-specific known issues](#faq-android)
    * [iOS-specific known issues](#faq-ios)
* [Additional info](#info)


# <a name="system-requirements"></a> System requirements

## <a name="hw-requirements"></a> Minimum hardware requirements

### Desktop platforms (Linux, MacOS)

- _BlinkID C SDK_ supports any `x86_64` compatible processor
    - x86, ARM, MIPS, SPARC, Power, Itanium and other non-x86_64-compatible CPUs are **not supported**
- 20 MB of available hard disk space
- 1 GB of RAM
    - the software may work even on systems with less RAM, but may fail to perform recognition of very large images
    - pure barcode recognition (no OCR) should also work on systems with around 128 MB of free RAM

### Mobile platforms (Android, iOS)

#### Android

- _BlinkID C SDK_ is compiled for following Android ABIs:
    - `armeabi-v7a`, `arm64-v8a`, `x86` and `x86_64`
- **Not supported ABIs**: `armeabi`, `mips` and `mips64`
- **Note about `armeabi-v7a`**:
    - only devices that have processor with support for [Advanced SIMD (NEON)](https://en.wikipedia.org/wiki/ARM_architecture#Advanced_SIMD_(NEON)) are supported
    - this means that certain `armeabi-v7a` CPUs, such as [NVIDIA Tegra 2](https://en.wikipedia.org/wiki/Tegra#Tegra_2) **are not supported**

#### iOS

- all iOS devices that have iOS 8.0 or newer are supported. Note that recognition performance can be low on older single-core iOS devices, such as iPhone 4.

## <a name="sw-requirements"></a> Minimum software requirements

### MacOS

- _BlinkID C SDK_ supports 64-bit Intel-based Macs with **Mac OS X 10.14 (Mojave)** or newer
- Note that SDK may work on earlier versions of MacOS, but we do not give any support nor guarantees for that.

### Linux

- _BlinkID C SDK_ supports Linux distributions that have **GLIBC 2.17** or newer
- additionally, for running bundled demo apps, a `libjpeg v8` is required
	- this is a dependency of the demo apps, not the SDK itself

### Android

- _BlinkID C SDK_ requires Android 4.1 (API level 16) or newer. The binary has been built with the latest NDK version available at the time of the release, but due to the C API, it should be both forward and backward compatible with any NDK version.

### iOS

- _BlinkID C SDK_ supports iOS 8.0 or newer. The binary has been built using the latest Xcode version available at the time of the release.

# <a name="integration"></a> Integration instructions

## <a name="pkg-contents"></a> Package contents

The _BlinkID C SDK_ consists of:

- [doxygen documentation](https://blinkid.github.io/blinkid-c-sdk)
- C headers exposing the public API of the SDK
    - located in [include](include) directory
    - on Apple platforms (MacOS and iOS), headers are bundled within the respective frameworks
        - iOS framework is available [here](lib/iOS)
        - MacOS framework is available [here](lib/MacOS)
- dynamic library that contains the implementation of the SDK
    - Android shared objects are available [here](lib/Android)
    - Linux shared objects are available [here](lib/Linux)
    - iOS dynamic framework is available [here](lib/iOS)
    - MacOS dynamic framework is available [here](lib/MacOS)
- resources that _BlinkID_ requires at runtime
    - resources for Android are available [here](resources/android)
    - resources for all other platforms are available [here](resources/non-android)

## <a name="configure-build"></a> Configuring your build system

In order to be able to use _BlinkID_ in your application, you first need to configure your build system to be able to find the API headers so that your code will be able to use _BlinkID's_ API functions. You also need to configure your build system to link with the dynamic library. Since there is no standard build system for C language, we created the most common examples for every OS _BlinkID C SDK_ supports.

### <a name="configure-linux"></a> Linux

On Linux, please make sure that you instruct your compiler to search for headers in [include](include) directory and to link with `libRecognizerApi.so`, which is located in [Linux lib folder](lib/Linux/x64). When running your app, make sure that `libRecognizerApi.so` is available in library search path by installing it to the default library directory (usually `/usr/lib`) or by setting `LD_LIBRARY_PATH` environment variable to folder containing the `libRecognizerApi.so`. While deploying your application, make sure that you also include the [resources](resources/non-android) that are needed at runtime. You will need to provide path to folder containing those resources during [the initialization of the SDK](#first-scan).

Please check [the Linux sample-app](sample-apps/projects/Linux/x64) for an example of integration of _BlinkID C SDK_ on Linux.

### <a name="configure-macos"></a> MacOS

On MacOS, _BlinkID C SDK_ is available as [dynamic framework](lib/MacOS). You can simply drag and drop the framework in your Xcode project and Xcode should automatically setup header and framework search paths for you. While deploying your application, make sure that you also include the [resources](resources/non-android) that are needed at runtime. You will need to provide path to folder containing those resources during [the initialization of the SDK](#first-scan).

Please check [the MacOS sample-app](sample-apps/projects/MacOS) for an example of integration of _BlinkID C SDK_ on MacOS.

### <a name="configure-android"></a> Android

On Android, please make sure that you instruct your compiler to search for headers in [include](include) directory and to link with `libRecognizerApi.so` for each android ABI. Libraries for all supported Android ABIs are located in [Android lib folder](lib/Android). When running your app, make sure that you load the `RecognizerApi` in Java code prior loading your own library, otherwise you will get `UnsatisfiedLinkException`. While deploying your application, make sure to include the [resources](resources/android) in your app's assets. You can put the resource files into any folder within your app's assets. You will need to provide path to folder containing those resources during [the initialization of the SDK](#first-scan). On Android, this path must be relative with respect to your app's assets folder. Also, make sure that you initialize the _BlinkID C SDK_ with your application's context using [`recognizerAPIInitializeAndroidApplication`](https://blinkid.github.io/blinkid-c-sdk/_recognizer_api_utils_8h.html#a6a39476a55beb625a6063e9129e02ff6) before making any other API calls.

Please check [the Android sample-app](sample-apps/projects/Android) for an example of integration of _BlinkID C SDK_ on Android.

### <a name="configure-ios"></a> iOS

On iOS, _BlinkID C SDK_ is available as [dynamic framework](lib/iOS). You can simply drag and drop the framework in your Xcode project and Xcode should automatically setup header and framework search paths for you. While deploying your application, make sure that you also include the [resources](resources/non-android) that are needed at runtime. You will need to provide path to folder containing those resources during [the initialization of the SDK](#first-scan).

Please check [the iOS sample-app](sample-apps/projects/iOS) for an example of integration of _BlinkID C SDK_ on iOS.

## <a name="obtaining-a-license-key"></a> Obtaining a license key

Using _BlinkID C SDK_ in your app requires a valid license key.

You can obtain a free trial license key by registering to [Microblink dashboard](https://microblink.com/login). After registering, you will be able to generate a license key for your app.

- On Android, the license key is bound to the [package name](http://tools.android.com/tech-docs/new-build-system/applicationid-vs-packagename) of your app.
- On iOS, the license key is bound to the [bundle identifier](https://stackoverflow.com/a/11347680/213057) of your app.
- On Linux, the license key is bound to the [machine ID](https://man7.org/linux/man-pages/man5/machine-id.5.html) of the computer that will run your app.
    - you can obtain the ID by running a [license request tool](lib/Linux/LicenseRequestTool). This utility will print the machine ID as `Licensee` to the standard output and also into file `MicroblinkLicenseRequest.txt`
    - if you need a linux license eligible for multiple machines, please [contact us](https://help.microblink.com)
- On MacOS, the license key is bound to the [Mac's UUID](https://www.engadget.com/2013-07-25-mac-101-finding-your-macs-uuid.html?guccounter=1)
    - you can obtain the ID by running a [license request tool](lib/MacOS/LicenseRequestTool). This utility will print the machine ID as `Licensee` to the standard output and also into file `MicroblinkLicenseRequest.txt`
    - if you need a macOS license eligible for multiple machines, please [contact us](https://help.microblink.com)

## <a name="first-scan"></a> Performing your first scan

1. Make sure that you have [set up your build system](#configure-build) and [obtained the license key](#obtaining-a-license-key).

1. Include a main SDK header, which provides all API functions:
    ```c
    #include <RecognizerApi.h>
    ```

1. (Android only) initialize Android JNI context. This is required on Android in order for license validation and resource loading to work.
    ```c
    // jniEnv is of type "JNIEnv *" and available to every JNI funcion
    // context is of type "jobject" and must point to instance "android.content.Context" java object. It is recommended to use application context
    // to avoid memory leaks. For more information, please see: https://android-developers.googleblog.com/2009/01/avoiding-memory-leaks.html
    recognizerAPIInitializeAndroidApplication( jniEnv, context );
    ```

1. Insert your license key
    ```c
    MBRecognizerErrorStatus errorStatus = recognizerAPIUnlockWithLicenseKey( "Add license key here" );
    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        // handle failure
    }
    ```

1. Set path to folder containing resources required by the library. The function `recognizerAPISetResourcesLocation` requires absolute path to folder containing all files from `resources/non-android` folder from the distribution on all platforms except Android. On Android it requires relative path to folder within `assets` containing all files from the `resources/android` folder from the distribution. For more information about that, check [the Android sample-app](sample-apps/projects/Android)
    ```c
    MBRecognizerErrorStatus errorStatus = recognizerAPISetResourcesLocation( "/path/to/resources/non-android" );
    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        // handle failure
    }
    ```

1. Create and configure recognizer. For more information about available recognizers, [check here](#available-recognizers)
    ```c
    MBBlinkIdRecognizer * blinkIdRecognizer = NULL;

    MBBlinkIdRecognizerSettings settings;

    // initialize default settings values
    blinkIdRecognizerSettingsDefaultInit( &settings );

    // optionally tweak settings for your needs

    MBRecognizerErrorStatus errorStatus = = blinkIdRecognizerCreate( &blinkIdRecognizer, &settings );
    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        // handle failure
    }
    ```

1. Create and configure recognizer runner
    ```c
    MBRecognizerRunnerSettings runnerSett;
    recognizerRunnerSettingsDefaultInit( &runnerSett );

    MBRecognizerPtr recognizers[] = { blinkIdRecognizer };

    runnerSett.numOfRecognizers = 1;
    runnerSett.recognizers = recognizers;

    MBRecognizerRunner * recognizerRunner = NULL;

    errorStatus = recognizerRunnerCreate( &recognizerRunner, &runnerSett );
    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        // handle failure
    }
    ```

1. Prepare the image to be recognized. Image first needs to be created from from memory. To create image from memory buffer use [`recognizerImageCreateFromRawImage`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_image.html#a15d9ff61beca923011ba0afc0ca9d58f)
    ```c
    int image_width, image_height, image_stride;
    MBByte * image_buffer;

    // populate above variables (i.e. by loading image file or capturing image with camera)

    MBRecognizerImage * img;
    MBRecognizerErrorStatus status = recognizerImageCreateFromRawImage( &img, image_buffer, image_width, image_height, image_stride, RAW_IMAGE_TYPE_BGR );
    if (status != RECOGNIZER_ERROR_STATUS_SUCCESS) {
        printf("Failed to create image. Reason: %s", recognizerErrorToString(status));
    }
    ```

1. Once you have created an image, you can perform recognition using method [`recognizerRunnerRecognizeFromImage`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner.html#a50678935556a9718df4ed4aaf89286c0).
    ```c
    MBRecognizerResultState resultState = recognizerRunnerRecognizeFromImage( recognizerRunner, imageWrapper.recognizerImage, MB_FALSE, NULL );

    if ( resultState != RECOGNIZER_RESULT_STATE_EMPTY )
    {
        // obtain results from recognizers (see Step 4)
    }
    ```

1. Obtain result structure from each of the recognizers. If some recognizer's result's state is [`RECOGNIZER_RESULT_STATE_VALID`](https://blinkid.github.io/blinkid-c-sdk/_recognizer_8h.html#a5ceb086a453c18e3da30aabbb8406bc0), then it contains recognized data.
    ```c
    MBBlinkIdRecognizerResult result;

    blinkIdRecognizerResult( &result, blinkIdRecognizer );

    if ( result.baseResult.state == RECOGNIZER_RESULT_STATE_VALID )
    {
        // you can use data from the result
    }
    ```

1. Finally, when done, clean the memory. Each structure has method for releasing it.
    ```c
    recognizerImageDelete( &img );
    recognizerRunnerDelete( &recognizerRunner );
    // make sure that recognizers are deleted *AFTER* recognizerRunner
    blinkIdRecognizerDelete( &blinkIdRecognizer );
    ```

# <a name="available-recognizers"></a> The `Recognizer` concept and the `RecognizerRunner`

This section will first describe [what is a `Recognizer`](#recognizer-concept) and how it should be used to perform recognition of the still images and video frames. Next, we will describe what is a [`RecognizerRunner`](#recognizer-runner) and how it can be used to tweak the recognition procedure.

## <a name="recognizer-concept"></a> The `Recognizer` concept

The `Recognizer` is the basic unit of processing within the _BlinkID_ SDK. Its main purpose is to process the image and extract meaningful information from it. As you will see [later](#recognizer-list), the _BlinkID_ SDK has lots of different `Recognizer` objects that have various purposes.

Each `Recognizer` has a `Result` object, which contains the data that was extracted from the image. The `Result` for each specific `Recognizer` can be obtained by creating a specific `Result` structure (each `Recognizer` has its own unique `Result` structure) and filling its contents by calling the `<recognizerName>RecognizerResult` function (each `Recognizer` has its own unique function for obtaining the results.) The pointers set by the result obtaining function are valid as long as the associated `Recognizer` object is alive, i.e. until `<recognizerName>RecognizerDelete` function is called. Keep that in mind while developing your application.

Every `Recognizer` is a stateful object that can be in two possible states: _idle state_ and _working state_.

While in _idle state_, you are allowed to call `<recognizerName>RecognizerUpdate` function which will update `Recognizer's` properties according to given settings.

After you create a `RecognizerRunner` with array containing your recognizer, the state of the `Recognizer` will change to _working state_, in which `Recognizer` object will be used for processing. While being in _working state_, it is not possible to call function `<recognizerName>RecognizerUpdate` with it as a parameter (calling it will crash your app). If you need to change configuration of your recognizer while its being used, you need to create a new `Recognizer` of the same type with your modified configuration and replace the original `Recognizer` within the `RecognizerRunner` by calling its [`recognizerRunnerUpdateSettings`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner.html#a9477518625bb5348140af7dc9edb85c1) method.

While `Recognizer` object works, it changes its internal state and its result. The `Recognizer` object's `Result` always starts in [`RECOGNIZER_RESULT_STATE_EMPTY`](https://blinkid.github.io/blinkid-c-sdk/_recognizer_8h.html#a5ceb086a453c18e3da30aabbb8406bc0) state. When corresponding `Recognizer` object performs the recognition of given image, its `Result` can either stay in `RECOGNIZER_RESULT_STATE_EMPTY` state (in case `Recognizer` failed to perform recognition), move to `RECOGNIZER_RESULT_STATE_UNCERTAIN` state (in case `Recognizer` performed the recognition, but not all mandatory information was extracted) or move to `RECOGNIZER_RESULT_STATE_VALID` state (in case `Recognizer` performed recognition and all mandatory information was successfully extracted from the image).

## <a name="recognizer-runner"></a> `RecognizerRunner`

The `RecognizerRunner` is the object that manages the chain of individual `Recognizer` objects within the recognition process. It's created by [`recognizerRunnerCreate`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner.html#a5c3e9b7dae397fcc7b86853abb3b61f2) function, which requires a [settings structure](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner_settings.html) which contains an array of `Recognizer` objects that will be used for processing and a [`MBBool allowMultipleResults` member](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner_settings.html#a09034aebf6ff97ae5f8b66c31f9a6432) indicating whether multiple `Recognizer` objects are allowed to have their `Results` enter the `RECOGNIZER_RESULT_STATE_VALID` state.

To explain further the `allowMultipleResults` parameter, we first need to understand how `RecognizerRunner` performs image processing.

When the [`recognizerRunnerRecognizeFromImage`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognizer_runner.html#a50678935556a9718df4ed4aaf89286c0) function is called, it processes the image with the first `Recognizer` in chain. If the `Recognizer's` `Result` object changes its state to `RECOGNIZER_RESULT_STATE_VALID`, then if the `allowMultipleResults` parameter is `MB_FALSE`, the recognition chain will be broken and `recognizerRunnerRecognizeFromImage` function will immediately return. If the `allowMultipleResults` parameter is `MB_TRUE`, then the image will also be processed with other `Recognizer` objects in chain, regardless of the state of their `Result` objects. If, after processing the image with the first `Recognizer` in chain, its `Result` object's state is not changed to `Valid`, the `RecognizerRunner` will use the next `Recognizer` object in chain for processing the image and so on - until the end of the chain (if no results become valid or always if `allowMultipleResults` parameter is `MB_TRUE`) or until it finds the `Recognizer` that has successfully processed the image and changed its `Result's` state to `RECOGNIZER_RESULT_STATE_VALID` (if `allowMultipleResults` parameter is `MB_FALSE`).

You cannot change the order of the `Recognizer` objects within the chain - no matter the order in which you give `Recognizer` objects to `RecognizerRunner`, they are internally ordered in a way that provides best possible performance and accuracy.

Also, in order for _BlinkID_ SDK to be able to order `Recognizer` objects in recognition chain in the best way possible, it is not allowed to have multiple instances of `Recognizer` objects of the same type within the chain. Attempting to do so will crash your application.

# <a name="recognition-callbacks"></a> Handling processing events with `RecognitionCallback`

Processing events, also known as _Recognition callbacks_ are purely intended for giving processing feedback on UI. If you do not plan developing any UI, you will most probably not need to use _Recognition callbacks_.

Callbacks for all possible events are bundled into the [`MBRecognitionCallback`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognition_callback.html) structure. We suggest checking for more information about available callbacks [in the doxygen documentation](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_recognition_callback.html).

# <a name="recognizer-list"></a> List of available recognizers

This section will give a list of all `Recognizer` objects that are available within _BlinkID_ SDK, their purpose and recommendations how they should be used to get best performance and user experience.
## <a name="idBarcodeRecognizer"></a> ID barcode recognizer

The [`IdBarcodeRecognizer`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_id_barcode_recognizer.html) is recognizer specialized for scanning barcodes from various ID cards.

You can find the list of the currently supported documents [here](IdBarcodeRecognizer.md).

## <a name="blinkidRecognizer"></a> BlinkID recognizer

The [`BlinkIdRecognizer`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_blink_id_recognizer.html) scans and extracts data from the single side of the supported document.

You can find the list of the currently supported documents [here](BlinkIdRecognizer.md). For detailed information about which fields can be extracted from each document, [check this link](BlinkIdDocumentFields.md).

We will continue expanding this recognizer by adding support for new document types in the future. Star this repo to stay updated.

## <a name="blinkidCombinedRecognizer"></a> BlinkID combined recognizer

Use [`BlinkIdCombinedRecognizer`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_blink_id_combined_recognizer.html) for scanning both sides of the supported document. First, it scans and extracts data from the front, then scans and extracts data from the back, and finally, combines results from both sides.

The [`BlinkIdCombinedRecognizer`](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_blink_id_combined_recognizer.html) also performs data matching and returns a flag if the extracted data captured from the front side matches the data from the back.

You can find the list of the currently supported documents [here](BlinkIdRecognizer.md). For detailed information about which fields can be extracted from each document, [check this link](BlinkIdDocumentFields.md).

We will continue expanding this recognizer by adding support for new document types in the future. Star this repo to stay updated.
# <a name="troubleshoot"></a> Troubleshooting

## <a name="integration-problems"></a> Integration problems

In case of problems with the integration of the SDK, first make sure that you have tried integrating the SDK exactly as described [in integration instructions](#integration).

If you have followed the instructions to the letter and you still have the problems, please try modifying a sample app so that it will reproduce the issue you are having and then contact us at [help.microblink.com](https://help.microblink.com).

## <a name="licensing-problems"></a> Licensing problems

If you are getting "invalid license key" error or having other license-related problems (e.g. some feature is not enabled that should be), first check the output of your program. All license-related problems are logged to the standard output for each platform (ADB on Android, NSLog on iOS, `stdout` on desktop platforms).

When you have to determine what is the license-related problem or you simply do not understand the log, you should contact us [help.microblink.com](http://help.microblink.com). When contacting us, please make sure you provide following information:

- `licensee` to which your license key is bound
    - for more information about obtaining the `licensee`, check [Obtaining a license key](#obtaining-a-license-key)
- license key that is causing problems
- please stress out that you are reporting problem to the _BlinkID C SDK_
- please add information about the operating system and its version
- if unsure about the problem, you should also provide excerpt from program output containing the license error

### <a name="other-problems"></a> Other problems

If you are having problems with scanning certain items, undesired behaviour on specific device(s), crashes inside _BlinkID_ or anything unmentioned, please do as follows:

- Contact us at [help.microblink.com](http://help.microblink.com) describing your problem and provide following information:
    - Log from the program output
    - high resolution scan/photo of the item that you are trying to scan
    - information about the operating system and its version
    - please stress out that you are reporting problem related to the _BlinkID C SDK_
    - in case of a crash, please provide a crash trace or even a coredump file
# <a name="faq"></a> FAQ and known issues

#### After switching from trial to production license I get error `This entity is not allowed by currently active license!` when I create a specific `Recognizer` object.

Each license key contains information about which features are allowed to use and which are not. This error indicates that your production license does not allow using of specific `Recognizer` object. You should contact [support](http://help.microblink.com) to check if provided license is OK and that it really contains all features that you have purchased.

#### Initialization of the `RecognizerRunner` fails

Please check that you have correctly set the license key and that you have correctly set the path to resources that need to be loaded at runtime. For more information, see [_performing your first scan_ article](#first-scan)

## <a name="faq-android"></a> Android-specific known issues

#### When my app starts, I get `UnsatisfiedLinkError`

This error happens when JVM fails to load some native method from native library. First make sure that you have loaded `RecognizerApi` in Java prior loading your native library. This should be added to Java class that interacts with your native library that uses _BlinkID_. For example:
```java
    static {
        System.loadLibrary("RecognizerApi");
        System.loadLibrary("myLibUsingRecognizerApi");
    }
```

Also, make sure that you have correctly combined _BlinkID_ SDK with third party SDKs that contain native code, i.e. that your final app contains matching ABIs for all libraries that ended up in the final library. For more information about that, check [this article in our BlinkID Android SDK documentation](https://github.com/blinkid/blinkid-android#combineNativeLibraries).

If you are getting this error also in our integration demo app, then it may indicate a bug in the SDK that is manifested on specific device. Please report that to our [support team](http://help.microblink.com).

#### Application crashes as soon as any _BlinkID C SDK_ API function is called

Make sure that you have initialized the SDK with your app's Application context before calling any other API function. For more information about that, check [this article in our BlinkID Android SDK documentation](https://github.com/blinkid/blinkid-android#combineNativeLibraries).

## <a name="faq-ios"></a> iOS-specific known issues

#### Unsupported architectures when submitting app to App Store

RecognizerApi.framework is a dynamic framework which contains slices for all architectures - device and simulator. If you intend to extract .ipa file for ad hoc distribution, you'll need to preprocess the framework to remove simulator architectures.

Ideal solution is to add a build phase after embed frameworks build phase, which strips unused slices from embedded frameworks.

Build step is based on the one provided here: http://ikennd.ac/blog/2015/02/stripping-unwanted-architectures-from-dynamic-libraries-in-xcode/

```shell
APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

# This script loops through the frameworks embedded in the application and
# removes unused architectures.
find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK
do
FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS
do
echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
done

echo "Merging extracted architectures: ${ARCHS}"
lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"
rm "$FRAMEWORK_EXECUTABLE_PATH"
mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done
```
# <a name="info"></a> Additional info

For any other questions, feel free to contact us at [help.microblink.com](http://help.microblink.com) or open a [new issue on GitHub](https://github.com/BlinkID/blinkid-c-sdk/issues).

## Important links

- [Doxygen documentation](https://blinkid.github.io/blinkid-c-sdk/index.html)
- [Release notes](Release%20notes.md)
- [Demo apps](sample-apps)
- [Microblink help and support](https://help.microblink.com)
    - or open a [new issue on GitHub](https://github.com/BlinkID/blinkid-c-sdk/issues)
