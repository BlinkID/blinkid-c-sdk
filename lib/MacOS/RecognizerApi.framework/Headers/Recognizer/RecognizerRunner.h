/**
 * @file RecognizerRunner.h
 *
 * Copyright (c)2015 MicroBlink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef RECOGNIZER_RUNNER_H_
#define RECOGNIZER_RUNNER_H_

#include "Export.h"
#include "Recognizer.h"
#include "RecognizerError.h"
#include "RecognizerImage.h"
#include "Rectangle.h"
#include "Types.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @struct MBRecognizerRunner
 * @brief MBRecognizerRunner data structure.
 *
 * Recognizer object specializes in finding elements (e.g. barcodes) on the image. Which elements are being
 * found is specified by RecognizerSettings object
 */
struct MBRecognizerRunner;

/**
 * @brief Typedef for MBRecognizerRunner structure.
 */
MB_EXPORTED_TYPE typedef struct MBRecognizerRunner MBRecognizerRunner;

struct MBRecognizerRunnerSettings;

/**
 * @brief Typedef for MBRecognizerRunnerSettings structure.
 */
typedef MB_EXPORTED_TYPE struct MBRecognizerRunnerSettings MBRecognizerRunnerSettings;

/**
 * @memberof MBRecognizerRunnerSettings
 * @brief Populate MBRecognizerRunnerSettings structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL recognizerRunnerSettingsDefaultInit( MBRecognizerRunnerSettings * );

/**
 * @struct MBRecognizerRunnerSettings
 * @brief Recognizer runner settings data structure
 *
 */
struct MBRecognizerRunnerSettings
{
    /**
     * Determines whether it is allowed to return multiple scan results from the same image. If this is not allowed (default),
     * then during recognition if some recognizer changes its result's state into RECOGNIZER_RESULT_STATE_VALID, the MBRecognizerRunner
     * will immediately stop the recognition chain and recognizers that are later in chain will not get a chance to process
     * that image. If you allow this, then even in that case all recognizers will get a chance to process the image, thus giving
     * chance for producing multiple recognition results from the same image (although not guaranteed).
     */
    MBBool allowMultipleResults;

    /**
     * Array of recognizers that will be used by the MBRecognizerRunner. If set to NULL, no recognizers will be used
     * by the recognizer runner.
     */
    MBRecognizerPtr const * recognizers;

    /**
     * Number of recognizers given in recognizers array.
     */
    size_t numOfRecognizers;

#ifdef __cplusplus
    MBRecognizerRunnerSettings()
    {
        recognizerRunnerSettingsDefaultInit( this );
    }
#endif
};

/**
  * @struct MBPoint
  * @brief This structure represents the 2D point.
  */
struct MBPoint
{
    /** x-coordinate of the point */
    int x;
    /** y-coordinate of the point */
    int y;
};

/**
 * @brief Typedef for MBPoint structure.
 */
typedef MB_EXPORTED_TYPE struct MBPoint MBPoint;

/**
  * @struct MBSize
  * @brief This structure represents the two-dimensional size of an object.
  */
struct MBSize
{
    /** width */
    int width;
    /** height */
    int height;
};

/**
 * @brief Typedef for MBSize structure.
 */
typedef MB_EXPORTED_TYPE struct MBSize MBSize;

/**
  * @enum MBDetectionStatus
  * @brief Defines a status of the object detection process.
  */
enum MBDetectionStatus
{
    /** Object has been detected successfully */
    DETECTION_STATUS_SUCCESS,
    /** Detection failed, nothing detected */
    DETECTION_STATUS_FAIL,
    /** Object detected, but the camera is too far above it */
    DETECTION_STATUS_CAMERA_TOO_HIGH,
    /** Object has been detected, but some parts of it are not in image */
    DETECTION_STATUS_PARTIAL_OBJECT,
    /** Object has been detected, but camera is at too big angle */
    DETECTION_STATUS_CAMERA_AT_ANGLE,
    /** Object detected, but the camera is too close to the object  */
    DETECTION_STATUS_CAMERA_TOO_NEAR,
    /** Document detected, but document is too close to the edge of the frame */
    DETECTION_STATUS_DOCUMENT_TOO_CLOSE_TO_EDGE
};

/**
 * @brief Typedef for MBDetectionStatus enum.
 */
typedef MB_EXPORTED_TYPE enum MBDetectionStatus MBDetectionStatus;

/**
* @enum MBShowImageType
* @brief Enumeration of types of images returned via onShowImage callback function
*/
enum MBShowImageType
{
    /** original image passed to recognizer */
    SHOW_IMAGE_TYPE_ORIGINAL,
    /** image with position and orientation adjusted and cropped for further processing */
    SHOW_IMAGE_TYPE_DEWARPED,
    /** final image resulting from a successful scan */
    SHOW_IMAGE_TYPE_SUCCESSFUL_SCAN
};

/**
 * @brief Typedef for the MBShowImageType enum.
 */
typedef MB_EXPORTED_TYPE enum MBShowImageType MBShowImageType;

struct MBRecognitionCallback;

/**
 * @brief Typedef for MBRecognitionCallback structure.
 */
typedef MB_EXPORTED_TYPE struct MBRecognitionCallback MBRecognitionCallback;

/**
 * @memberof MBRecognitionCallback
 * @brief Populate MBRecognitionCallback structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL recognitionCallbackDefaultInit( MBRecognitionCallback * );

/**
 * @struct MBRecognitionCallback
 * @brief The MBRecognitionCallback struct
 *
 * This structure contains pointers to functions that can be called in various parts
 * of the recognition process. Functions will be called only if non-NULL function pointer
 * is given. All functions except onDetectionFailed may be called multiple times whilst
 * processing a single image - each recognizer object will call them separately.
 */
struct MBRecognitionCallback
{

    /** Called when object detection on image starts. */
    void (*onDetectionStarted)();

    /**
     * Called when the recognizer is midway the detection. At that point
     * some points could be drawn on to the frame as a sign of something happening.
     *
     *  @param  points array of points that represent the detected object (usually 4 points, but can be less or
     *          more for some specific object (for example: QR code)). Point coordinates are
     *          in image-based coordinate system, i.e. (0,0) is the coordinate of upper left corner
     *          and (width, height) is the coordinate of lower right corner of the image.
     *          If no points are given, this pointer is NULL.
     *  @param  pointsSize size of the array points
     *
     */
    void (*onDetectionMidway)( MBPoint const * points, size_t pointsSize );

    /** Called when object detection on image finishes. If processing should proceed to
     *  recognition of the detected object, method must return MB_TRUE.
     *  @param  points array of points that represent the detected object (usually 4 points, but can be less or
     *          more for some specific object (for example: QR code)). Point coordinates are
     *          in image-based coordinate system, i.e. (0,0) is the coordinate of upper left corner
     *          and (width, height) is the coordinate of lower right corner of the image.
     *          If no points are given, this pointer is NULL.
     *  @param  pointsSize size of the array points
     *  @param  detectionStatus status of the object detection. Can be any from the DetectionStatus enum.
     *  @return MB_TRUE if recognition should proceed. MB_FALSE if recognition should not proceed.
     */
    MBBool (*onDetectedObject)( MBPoint const * points, size_t pointsSize, MBDetectionStatus detectionStatus );

    /** Called when whole chain of recognizers failed and nothing has been detected on image.
     *  Note that this method is called only if all recognizers in recognizer chain fail to
     *  detect anything, while onDetectedObject will be called for each recognizer separately.
     *
     *  For example, if the image contains PDF417 code and both barcode recognizer (configured for QR code scanning only) and USDL
     *  recognizer are in chain, then the barcode recognizer will call onDetectedObject with detection status DETECTION_STATUS_FAIL,
     *  while USDL recognizer will call onDetectedObject with DETECTION_STATUS_SUCCESS and this method will not be called.
     *  On the other hand, if image doesn't contain anything, both barcode recognizer and USDL recognizer will call onDetectedObject
     *  with DETECTION_STATUS_FAIL and then this method will be called.
     */
    void (*onDetectionFailed)();

    /** Called when recognition process starts */
    void (*onRecognitionStarted)();

    /** Called when recognition process ends, just before returning from the recognizerRecognizeFromImage method */
    void (*onRecognitionFinished)();

    /** Called when recognition process produces an image in various stages of recognition. showType parameter
     *  can be used to differentiate between image types so only images that are needed are handled.
     *	@param	image       returned image. Image pointer is valid only during the scope of the function. If you need it later, you should
     *                      copy the image with ::recognizerImageCreateCopyFromImage.
     *  @param  showType    type of shown image.
     *  @param  name        image name. Can be NULL.
     *
     *  @see MBShowImageType for more information of what kinds of images are available
     */
    void (*onShowImage)( MBRecognizerImage const * image, MBShowImageType showType, char const * name );

    /**
     * Called when first side recognition with the combined recognizer completes.
     */
    void (*onFirstSideResult)();

    /**
     * Called when glare detection has completed with result whether glare has been found or not.
     * @param hasGlare indicates whether glare has been found on the input image or not
     */
    void (*onGlare)( MBBool hasGlare );

#ifdef __cplusplus
    /**
     * Default constructor for c++.
     */
    MBRecognitionCallback()
    {
        recognitionCallbackDefaultInit( this );
    }
#endif
};

/**
 * @memberof MBRecognizerRunner
 * @brief Allocates and initializes the recognizer runner object.
 *
 * @param recognizerRunner Pointer to pointer referencing the created recognizer runner object
 * @param settings         Required for initializing the recognizer runner
 *
 * @return status of the operation. The operation might fail, so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerCreate( MBRecognizerRunner ** recognizerRunner, MBRecognizerRunnerSettings const * settings );

/**
 * @memberof MBRecognizerRunner
 * @brief Updates recognizer runner's settings.
 * You can use this method to change what recognizers are active.
 *
 * @param recognizerRunner recognizer runner object that will be updated with new settings
 * @param settings         settings that will be applied
 *
 * @return status of the operation. The operation might fail, so please check returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerUpdateSettings( MBRecognizerRunner * recognizerRunner, MBRecognizerRunnerSettings const * settings );

/**
 * @memberof MBRecognizerRunner
 * @brief Deletes the recognizer runner object and sets a pointer to it to NULL.
 * Note that recognizers that were in use by the MBRecognizerRunner remain alive, but are no
 * longer used by the (now destroyed) MBRecognizerRunner. To avoid memory leaks you should
 * destroy each recognizer using its appropriate delete method.
 * Also note that if you destroy any of the recognizers that are in use by the recognizer runner
 * before deleting the runner, you will crash your app. The reason for this is that during deletion
 * of the runner, it needs to perform some termination tasks on each of the recognizers it used.
 *
 * @param recognizerRunner Double Pointer to the recognizer runner object which is to be deleted
 *
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerDelete( MBRecognizerRunner ** recognizerRunner );

/**
 * @memberof MBRecognizerRunner
 * @brief Sets the scanning region of interest. All subsequent calls to recognizerRecognizeFromImage will perform scans only in given ROI.
 * ROI must be given with relative dimensions, i.e. all dimensinos of given rectangle must be from interval [0.f, 1.f], where for x
 * coordinate and rectangle width dimension represents the percentage of image widht, and for y coordinate and rectangle height
 * dimension represents the percentage of image height.
 * Call this function with NULL to disable current ROI settings. If any dimension in ROI is larger than 1.f or smaller than 0.f, they
 * will be clamped to interval [0.f, 1.f].
 *
 * @param      recognizerRunner Pointer to the recognizer runner object to which ROI will be set
 * @param      regionOfInterest Pointer to rectangle that represents the ROI, or NULL to disable ROI.
 *
 * @return Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerSetROI( MBRecognizerRunner * recognizerRunner, MBRectangle const * regionOfInterest );

/**
 * @memberof MBRecognizerRunner
 * @brief Performs recognition of given image.
 *
 * @param recognizerRunner      object which performs recognition. Only recognizers given in MBRecognizerRunnerSettings will
 *                              be used for performing the recognition.
 * @param image                 MBRecognizerImage object which holds image on which recognition will be performed.
 *                              See MBRecognizerImage to see details on supported image formats.
 * @param imageIsVideoFrame     If MB_TRUE is given, image is treated as video frame. When treating image as video frame,
 *                              multiple consecutive frame may be combined to yield better recognition result. Note that if
 *                              consecutive calls to this method with this parameter set as MB_TRUE expect the consecutive
 *                              frames obtained from camera - all these frames should contain the same object that needs to be
 *                              recognised. If one of this frames contain different object, total recognition result may be
 *                              corrupted. To reset recognizer to initial setting, call ::recognizerRunnerReset.
 *                              Also note that returned recognition status may be RECOGNIZER_RESULT_STATE_EMPTY or
 *                              RECOGNIZER_RESULT_STATE_UNCERTAIN for frames for which library concludes are too poor to be processed.
 *                              If you want to force library to process every frame, set this parameter to MB_FALSE. In that case
 *                              time redundancy information from consecutive frames will not be used for recognition improvement.
 * @param callback              Pointer to structure that contains pointer to callback functions. If given NULL,
 *                              no callback will be called. If given non-NULL, only non-NULL function pointers will be called.
 *
 * @return General state of the recognition run. If RECOGNIZER_RESULT_STATE_EMPTY is returned, this means that no recognizer
 *         used by the MBRecognizerRunner recognised anything. If RECOGNIZER_RESULT_STATE_UNCERTAIN is returned, this means
 *         that at least one recognizer used by the MBRecognizerRunner changed its result's state into RECOGNIZER_RESULT_STATE_UNCERTAIN.
 *         If RECOGNIZER_RESULT_STATE_VALID is returned, this means that at least one recognizer used by the MBRecognizerRunner
 *         changed its result's state into RECOGNIZER_RESULT_STATE_VALID.
 */
MB_API MBRecognizerResultState MB_CALL recognizerRunnerRecognizeFromImage
(
    MBRecognizerRunner          * recognizerRunner,
    MBRecognizerImage     const * image,
    MBBool                        imageIsVideoFrame,
    MBRecognitionCallback const * callback
);


/**
 * @memberof MBRecognizerRunner
 * @brief Performs recognition of given string. Recognition from string is available only for US Driver's License recognizer.
 *
 * @param recognizerRunner  object which performs recognition. Only recognizers given in MBRecognizerRunnerSettings will
 *                          be used for performing the recognition.
 * @param string            String on which recognition will be performed.
 * @param callback          Pointer to structure that contains pointer to callback functions. If given NULL,
 *                          no callback will be called. If given non-NULL, only non-NULL function pointers will be called.
 *
 * @return General state of the recognition run. If RECOGNIZER_RESULT_STATE_EMPTY is returned, this means that no recognizer
 *         used by the MBRecognizerRunner recognised anything. If RECOGNIZER_RESULT_STATE_UNCERTAIN is returned, this means
 *         that at least one recognizer used by the MBRecognizerRunner changed its result's state into RECOGNIZER_RESULT_STATE_UNCERTAIN.
 *         If RECOGNIZER_RESULT_STATE_VALID is returned, this means that at least one recognizer used by the MBRecognizerRunner
 *         changed its result's state into RECOGNIZER_RESULT_STATE_VALID.
 */
MB_API MBRecognizerResultState MB_CALL recognizerRunnerRecognizeFromString
(
    MBRecognizerRunner          * recognizerRunner,
    char                  const * string,
    MBRecognitionCallback const * callback
);


/**
 * @memberof MBRecognizerRunner
 * @brief Cancels the current recognition process (if any).
 *
 * If there is a ongoing recognition process (i.e. ongoing call to recognizerRecognizeFromImage), this function will cancel the process.
 * The recognizers used by the MBRecognizerRunner will contain results they had at the time of cancelling.
 * If there is no ongoing recognition process, this function does nothing (it WILL NOT prevent recognition of next image given with call
 * to ::recognizerRunnerRecognizeFromImage that follows at any time after calling this function).
 *
 * @param recognizerRunner Recognizer runner object whose recognition process should be cancelled
 *
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerCancelCurrentRecognition( MBRecognizerRunner * recognizerRunner );

/**
 * @memberof MBRecognizerRunner
 * @brief Resets all recognizers used by the MBRecognizerRunner to the default state.
 *
 * When using method ::recognizerRunnerRecognizeFromImage with parameter imageIsVideoFrame set to MB_TRUE, multiple consecutive video frames
 * are used to obtain time redundancy information and yield better recognition result. To be able to do that, library will cache some
 * information from each frame that is later used for boosting the recognition quality. This method will purge that cache. In Microblink's
 * mobile SDKs this method is usually called when device gets shaken or new camera session starts.
 *
 * If you are not using video frames for recognition, this method is not neccessary.
 *
 * @param recognizerRunner object which performs recognition.
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerRunnerReset( MBRecognizerRunner * recognizerRunner );

#ifdef __cplusplus
}
#endif

#endif
