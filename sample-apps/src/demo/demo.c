#include <LicenseKey.h>
#include <RecognizerImageWrapper.h>

#include <RecognizerApi.h>

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
    /* Generic ID recognizer will be used for performing recognition of image that contains front side of the ID document */
    MBBlinkIdRecognizer * idRecognizer    = NULL;
    /* Recognizer runner is the main object that orchestrates recognition using one or more recognizers */
    MBRecognizerRunner * recognizerRunner = NULL;
    /* This is a helper struct for loading MBRecognizerImage from file */
    RecognizerImageWrapper imageWrapper;
    /* Most of the functions from the Recognizer API return error status to indicate whether operation succeeded or not */
    MBRecognizerErrorStatus errorStatus;

    MBBool recognitionSuccessfull = MB_FALSE;

    if (argc < 3) {
        printf("usage %s <path_to_resources_dir> <path_to_image> \n", argv[0]);
        return EXIT_FAILURE;
    }

    recognizerAPISetCacheLocation( "." );

    /* load the image from given path */
    imageWrapper = loadImageFromFile( argv[ 2 ] );

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

    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        printf( "Failed to unlock! Reason: %s\n", recognizerErrorToString( errorStatus ) );
        return EXIT_FAILURE;
    }

    /* Define path to resource directory */
    errorStatus = recognizerAPISetResourcesLocation( argv[ 1 ] );

    if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
    {
        printf( "Failed to set resources location!\n" );
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
        if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
        {
            printf( "Failed to create Generic ID recognizer!\n" );
            /* avoid memory leaks - free already allocated things */
            terminateImageWrapper( &imageWrapper );
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
        if ( errorStatus != RECOGNIZER_ERROR_STATUS_SUCCESS )
        {
            printf( "Failed to create recognizer runner!\n" );
            /* avoid memory leaks - free already allocated things */
            blinkIdRecognizerDelete( &idRecognizer );
            terminateImageWrapper  ( &imageWrapper );
            return EXIT_FAILURE;
        }
    }

    /* Step 3: Perform recognition of the image */
    {
        MBRecognizerResultState resultState;

        resultState = recognizerRunnerRecognizeFromImage( recognizerRunner, imageWrapper.recognizerImage, MB_FALSE, NULL );

        /* if at least one recognizer produced a result */
        if ( resultState != RECOGNIZER_RESULT_STATE_EMPTY )
        {
            /* Step 4: obtain results from the generic ID recognizer */
            MBBlinkIdRecognizerResult result;

            blinkIdRecognizerResult( &result, idRecognizer );

            if ( result.baseResult.state == RECOGNIZER_RESULT_STATE_VALID )
            {
                printf( "Result is valid!\n" );
                printf( "First name: %s.\n", result.firstName );
                printf( "Last name: %s\n"  , result.lastName );

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
    terminateImageWrapper( &imageWrapper );

    /*
     * NOTE: You must delete Recognizer runner before deleting any of the recognizers it
     *       currently uses. Otherwise a crash will occur.
     */
    recognizerRunnerDelete( &recognizerRunner );

    blinkIdRecognizerDelete( &idRecognizer );

    return ( recognitionSuccessfull ? EXIT_SUCCESS : EXIT_FAILURE );
}
