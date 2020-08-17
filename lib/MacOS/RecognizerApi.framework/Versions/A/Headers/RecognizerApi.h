/**
 * @file RecognizerApi.h
 *
 * @mainpage %C SDK documentation
 *
 * @section quickStart Quick start
 *
 * In order to perform recognition, you first need to create a concrete recognizer object. Each recognizer object is specific
 * for each object that needs to be scanned. After creating required recognizer objects, you need to create recognizer runner
 * object that will use given recognizer objects to perform recognition of images.
 *
 * A simple example that uses generic ID recognizer to scan information from any ID document would look like this:
 *
 * -# (Android only) initialize Android JNI context. This is required on Android in order for license validation and resource loading to work.
 *      @code
 *          // jniEnv is of type "JNIEnv *" and available to every JNI funcion
 *          // context is of type "jobject" and must point to instance "android.content.Context" java object. It is recommended to use application context
 *          // to avoid memory leaks. For more information, please see: https://android-developers.googleblog.com/2009/01/avoiding-memory-leaks.html
 *          recognizerAPIInitializeAndroidApplication( jniEnv, context );
 *      @endcode
 *
 * -# Insert your license key
 *      @code
 *          MBRecognizerErrorStatus errorStatus = recognizerAPIUnlockWithLicenseKey( "Add license key here" );
 *          if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
 *          {
 *              // handle failure
 *          }
 *      @endcode
 *
 * -# Set path to folder containing resources required by the library. The function ::recognizerAPISetResourcesLocation requires absolute path to folder containing all files from "resources/non-android" folder from the distribution on all platforms except Android. On Android it requires relative path to folder within "assets" containing all files from the "resources/android" folder from the distribution.
 *      @code
 *          MBRecognizerErrorStatus errorStatus = recognizerAPISetResourcesLocation( "/path/to/resources/non-android" );
 *          if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
 *          {
 *              // handle failure
 *          }
 *      @endcode
 * -# Create and configure generic ID recognizer
 *      @code
 *          MBBlinkIdRecognizer * blinkIdRecognizer = NULL;
 *
 *          MBBlinkIdRecognizerSettings idSettings;
 *
 *          // initialize default settings values
 *          blinkIdRecognizerSettingsDefaultInit( &idSettings );
 *
 *          // optionally tweak settings for your needs
 *          idSettings.allowBlurFilter           = MB_TRUE;
 *          idSettings.allowUnparsedMrzResults   = MB_FALSE;
 *          idSettings.allowUnverifiedMrzResults = MB_FALSE;
 *          idSettings.validateResultCharacters  = MB_TRUE;
 *
 *          MBRecognizerErrorStatus errorStatus = = blinkIdRecognizerCreate( &blinkIdRecognizer, &idSettings );
 *          if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
 *          {
 *              // handle failure
 *          }
 *      @endcode
 *
 * -# Create and configure recognizer runner
 *      @code
 *          MBRecognizerRunnerSettings runnerSett;
 *          recognizerRunnerSettingsDefaultInit( &runnerSett );
 *
 *          MBRecognizerPtr recognizers[] = { blinkIdRecognizer };
 *
 *          runnerSett.numOfRecognizers = 1;
 *          runnerSett.recognizers = recognizers;
 *
 *          MBRecognizerRunner * recognizerRunner = NULL;
 *
 *          errorStatus = recognizerRunnerCreate( &recognizerRunner, &runnerSett );
 *          if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
 *          {
 *              // handle failure
 *          }
 *      @endcode
 *
 * -# Prepare the image to be recognized. Image first needs to be created from from memory. To create image from memory buffer use ::recognizerImageCreateFromRawImage.
 *    @code
 *      int image_width, image_height, image_stride;
 *      MBByte * image_buffer;
 *
 *      // populate above variables (i.e. by loading image file or capturing image with camera)
 *
 *      MBRecognizerImage* img;
 *      MBRecognizerErrorStatus status = recognizerImageCreateFromRawImage( &img, image_buffer, image_width, image_height, image_stride, RAW_IMAGE_TYPE_BGR );
 *      if (status != RECOGNIZER_ERROR_STATUS_SUCCESS) {
 *          printf("Failed to create image. Reason: %s", recognizerErrorToString(status));
 *      }
 *    @endcode
 *
 * -# Once you have created an image, you can perform recognition using method ::recognizerRunnerRecognizeFromImage.
 *    @code
 *      MBRecognizerResultState resultState = recognizerRunnerRecognizeFromImage( recognizerRunner, imageWrapper.recognizerImage, MB_FALSE, NULL );
 *
 *      if ( resultState != RECOGNIZER_RESULT_STATE_EMPTY )
 *      {
 *          // obtain results from recognizers (see Step 4)
 *      }
 *    @endcode
 *
 * -# Obtain result structure from each of the recognizers. If some recognizer's result's state is RECOGNIZER_RESULT_STATE_VALID, then it contains recognized data.
 *      @code
 *          MBBlinkIdRecognizerResult result;
 *
 *          blinkIdRecognizerResult( &result, blinkIdRecognizer );
 *
 *          if ( result.baseResult.state == RECOGNIZER_RESULT_STATE_VALID )
 *          {
 *              // you can use data from the result
 *          }
 *      @endcode
 *
 * -# Finally, when done, clean the memory. Each structure has method for releasing it.
 *    @code
 *      recognizerImageDelete( &img );
 *      recognizerRunnerDelete( &recognizerRunner );
 *      // make sure that recognizers are deleted *AFTER* recognizerRunner
 *      blinkIdRecognizerDelete( &blinkIdRecognizer );
 *    @endcode
 *
 * @section info Additional info
 *
 * For any inquiries, additional information or instructions please contact us at <a href="http://help.microblink.com">help.microblink.com</a>.
 * When contacting, please state which product and which platform you are using so we can help you more quickly. Also, please state that you are using
 * C SDK and state the version you are using. You can obtain the library version with function ::recognizerAPIGetVersionString.
 */
#ifndef RECOGNIZERAPI_H_
#define RECOGNIZERAPI_H_

#include "Recognizer/AvailableRecognizers.h"
#include "Recognizer/Licensing.h"
#include "Recognizer/Recognizer.h"
#include "Recognizer/RecognizerApiUtils.h"
#include "Recognizer/RecognizerError.h"
#include "Recognizer/RecognizerImage.h"
#include "Recognizer/RecognizerRunner.h"

#endif
