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

#include "RecognizerImageWrapper.h"

#include <wincodec.h>
#include <stdio.h>

RecognizerImageWrapper loadImageFromFile( const char* filePath ) {
    RecognizerImageWrapper image;

    /* required for obtaining WinAPI result codes */
    HRESULT hr = S_OK;
    /* Imaging factory required to create image decoder */
    IWICImagingFactory* pImagingFactory = NULL;
    /* WIC image decoder that will be used for decoding the image */
    IWICBitmapDecoder *pIDecoder = NULL;
    /* WIC image frame - result of image decoding */
    IWICBitmapFrameDecode *pIDecoderFrame = NULL;
    /* wide path that is required for WIC */
    WCHAR* pathString = NULL;
    /* Width and height of the loaded image */
    UINT wicWidth = 0;
    UINT wicHeight = 0;
    /* Image format converter */
    IWICFormatConverter *pIFormatConverter = NULL;

    image.recognizerImage = NULL;
    image.imageBuffer = NULL;

    CoInitialize( NULL );

    /* Use Windows Imaging Component API to load the image from file */
    hr = CoCreateInstance(
        &CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        &IID_IWICImagingFactory,
        ( LPVOID* )&pImagingFactory
    );

    if( FAILED( hr ) ) {
        printf( "Failed to load Windows Image Component API\n" );
        return image;
    }

    /* convert normal path to wide path */
    size_t pathLen = strlen( filePath );
    pathString = ( WCHAR* )malloc( ( pathLen + 1 ) * sizeof( wchar_t ) );
    mbstowcs( pathString, filePath, pathLen );
    pathString[ pathLen ] = 0;

    hr = pImagingFactory->lpVtbl->CreateDecoderFromFilename(
        pImagingFactory,
        pathString,                     /* Image to be decoded */
        NULL,                           /* Do not prefer a particular vendor */
        GENERIC_READ,                   /* Desired read access to the file */
        WICDecodeMetadataCacheOnDemand, /* Cache metadata when needed */
        &pIDecoder                      /* Pointer to the decoder */
    );

    if( SUCCEEDED( hr ) ) {
        hr = pIDecoder->lpVtbl->GetFrame( pIDecoder, 0, &pIDecoderFrame );
    }
    else {
        printf( "Failed to create decoder from filename!\n" );
        return image;
    }

    hr = pImagingFactory->lpVtbl->CreateFormatConverter( pImagingFactory, &pIFormatConverter );
    if( SUCCEEDED( hr ) ) {
        hr = pIFormatConverter->lpVtbl->Initialize(
            pIFormatConverter,
            ( IWICBitmapSource * )pIDecoderFrame,                  /* Input bitmap to convert */
            &GUID_WICPixelFormat32bppPBGRA,  /* Destination pixel format */
            WICBitmapDitherTypeNone,         /* Specified dither pattern */
            NULL,                            /* Specify a particular palette */
            0.f,                             /* Alpha threshold */
            WICBitmapPaletteTypeCustom       /* Palette translation type */
        );
    }
    else {
        printf( "Failed to create pixel format converter\n" );
        return image;
    }

    /* Obtain image size */
    hr = pIDecoderFrame->lpVtbl->GetSize( pIDecoderFrame, &wicWidth, &wicHeight );

    /* Allocate buffer that will hold decoded pixels */
    image.imageBuffer = ( unsigned char* )malloc( wicWidth * 4 * wicHeight );

    /* Now decode the image */
    hr = pIDecoderFrame->lpVtbl->CopyPixels(
        pIDecoderFrame,
        NULL,
        wicWidth * 4,
        wicWidth * 4 * wicHeight,
        image.imageBuffer
    );

    if( FAILED( hr ) ) {
        printf( "Failed to decode image\n" );
        free( image.imageBuffer );
        image.imageBuffer = NULL;
        return image;
    }

    recognizerImageCreateFromRawImage( &image.recognizerImage, image.imageBuffer, wicWidth, wicHeight, wicWidth * 4, RAW_IMAGE_TYPE_BGRA );

    free( pathString );
    pIDecoderFrame->lpVtbl->Release( pIDecoderFrame );
    pIDecoder->lpVtbl->Release( pIDecoder );
    pImagingFactory->lpVtbl->Release( pImagingFactory );

    return image;
}

void terminateImageWrapper( RecognizerImageWrapper* image ) {
    recognizerImageDelete( &image->recognizerImage );
    free( image->imageBuffer );
}
