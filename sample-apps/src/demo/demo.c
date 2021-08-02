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

#include "Recognizer/RecognizerImage.h"
#include <LicenseKey.h>

#include <RecognizerApi.h>

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
    /* Generic ID recognizer will be used for performing recognition of image that contains front side of the ID document */
    MBBlinkIdRecognizer * idRecognizer    = NULL;
    /* Recognizer runner is the main object that orchestrates recognition using one or more recognizers */
    MBRecognizerRunner * recognizerRunner = NULL;
    /* This is the image that will be processed */
    MBRecognizerImage * image = NULL;
    /* Most of the functions from the Recognizer API return error status to indicate whether operation succeeded or not */
    MBRecognizerErrorStatus errorStatus;

    MBBool recognitionSuccessfull = MB_FALSE;

    if (argc < 3) {
        printf("usage %s <path_to_resources_dir> <path_to_image> \n", argv[0]);
        return EXIT_FAILURE;
    }

    recognizerAPISetCacheLocation( "." );

    /* Unlock the Recognizer API with your license key */

#if defined LICENSE_KEY && defined LICENSEE
    errorStatus = recognizerAPIUnlockForLicenseeWithLicenseKey( LICENSE_KEY, LICENSEE );
#elif defined LICENSE_KEY
    errorStatus = recognizerAPIUnlockWithLicenseKey( LICENSE_KEY );
#else
    /* insert license key and licensee */
    errorStatus = recognizerAPIUnlockForLicenseeWithLicenseKey( "Add license key here", "Add licensee here" );
    /* OR insert license key for licensee obtained with LicenseRequestTool */
    errorStatus = recognizerAPIUnlockWithLicenseKey( "Add license key here" );
#endif

    if ( errorStatus != MB_RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        printf( "Failed to unlock! Reason: %s\n", recognizerErrorToString( errorStatus ) );
        return EXIT_FAILURE;
    }

    /* Define path to resource directory */
    errorStatus = recognizerAPISetResourcesLocation( argv[ 1 ] );

    if ( errorStatus != MB_RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        printf( "Failed to set resources location!\n" );
        return EXIT_FAILURE;
    }

    /* load the image from given path */
    errorStatus = recognizerImageLoadFromFile( &image, argv[ 2 ] );
    if ( errorStatus != MB_RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        printf( "Failed to load image '%s'. Reason: %s\n", argv[ 2 ], recognizerErrorToString( errorStatus ) );
        return EXIT_FAILURE;
    }

    /* Step 1: Create and configure Generic ID recognizer */
    {
        /*
         * Generic ID Recognizer settings structure contains all configuration options that are available for the Generic ID recognizer.
         * Please note that in C++ a default constructor will be invoked when instantiating this structure, but in C code
         * you need to set all values manually, or use blinkIdRecognizerSettingsDefaultInit function, like here.
         */
        MBBlinkIdRecognizerSettings idSett;

        blinkIdRecognizerSettingsDefaultInit( &idSett );

        /* To create Generic ID recognizer using settings structure, you shuold call blinkIdRecognizerCreate function. */
        errorStatus = blinkIdRecognizerCreate( &idRecognizer, &idSett );
        if ( errorStatus != MB_RECOGNIZER_ERROR_STATUS_SUCCESS )
        {
            printf( "Failed to create Generic ID recognizer!\n" );
            /* avoid memory leaks - free already allocated things */
            recognizerImageDelete( &image );
            return EXIT_FAILURE;
        }
    }

    /* Step 2: Create and configure recognizer runner with Generic ID recognizer */
    {
        /*
         * Recognizer runner needs to be configured with MBRecognizerRunnerSettings structure, that will give
         * information about which recognizers should be used and whether or not multiple results per image
         * is allowed.
         */
        MBRecognizerRunnerSettings runnerSett;

        /* Initialize structure to default values */
        recognizerRunnerSettingsDefaultInit( &runnerSett );

        /*
         * This is an array of pointers to recognizers that will be used to pass information about desired
         * recognizers to the recognizer runner.
         */
        MBRecognizerPtr recognizers[ 1 ];

        runnerSett.allowMultipleResults = MB_FALSE;
        recognizers[ 0 ] = idRecognizer;

        runnerSett.numOfRecognizers = 1;
        runnerSett.recognizers = recognizers;

        errorStatus = recognizerRunnerCreate( &recognizerRunner, &runnerSett );
        if ( errorStatus != MB_RECOGNIZER_ERROR_STATUS_SUCCESS )
        {
            printf( "Failed to create recognizer runner!\n" );
            /* avoid memory leaks - free already allocated things */
            blinkIdRecognizerDelete( &idRecognizer );
            recognizerImageDelete( &image );
            return EXIT_FAILURE;
        }
    }

    /* Step 3: Perform recognition of the image */
    {
        MBRecognizerResultState resultState;

        resultState = recognizerRunnerRecognizeFromImage( recognizerRunner, image, MB_FALSE, NULL );

        /* if at least one recognizer produced a result */
        if ( resultState != MB_RECOGNIZER_RESULT_STATE_EMPTY )
        {
            /* Step 4: obtain results from the generic ID recognizer */
            MBBlinkIdRecognizerResult result;

            blinkIdRecognizerResult( &result, idRecognizer );

            if ( result.common.baseResult.state == MB_RECOGNIZER_RESULT_STATE_VALID )
            {
                printf( "Result is valid!\n" );
                printf( "First name: %s.\n", result.common.firstName );
                printf( "Last name: %s\n"  , result.common.lastName );

                recognitionSuccessfull = MB_TRUE;
            }
            else
            {
                printf( "Invalid result!\n" );
            }
        }
        else
        {
            printf( "Nothing recognized!\n" );
        }
    }

    /* Step 5: free all allocated resources */
    recognizerImageDelete( &image );

    /*
     * NOTE: You must delete Recognizer runner before deleting any of the recognizers it
     *       currently uses. Otherwise a crash will occur.
     */
    recognizerRunnerDelete( &recognizerRunner );

    blinkIdRecognizerDelete( &idRecognizer );

    return ( recognitionSuccessfull ? EXIT_SUCCESS : EXIT_FAILURE );
}
