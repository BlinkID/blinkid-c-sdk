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

#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

/* read the image using libjpeg */
/* code based on example from Github: https://github.com/ellzey/libjpeg/blob/master/example.c ) */
RecognizerImageWrapper loadImageFromFile( const char* filePath ) {
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	/* source image file */
	FILE * infile;
	JSAMPARRAY buffer;	/* Output row buffer */
	int row_stride;		/* physical row width in output buffer */
	unsigned char r,g,b;
	unsigned char* dummy;
	RecognizerImageWrapper result;

	result.recognizerImage = NULL;
	result.imageBuffer	   = NULL;

	if ((infile = fopen(filePath, "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", filePath);
		return result;
	}

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, infile);
	(void) jpeg_read_header(&cinfo, TRUE);
	(void) jpeg_start_decompress(&cinfo);

	result.imageBuffer = ( unsigned char* )malloc( cinfo.output_width * cinfo.output_height * 3 );
	dummy = result.imageBuffer;

	row_stride = cinfo.output_width * cinfo.output_components;
	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	while (cinfo.output_scanline < cinfo.output_height) {
		int x; /* for loop counter (this example is C89-compatible) */

		(void) jpeg_read_scanlines(&cinfo, buffer, 1);

		/* RecognizerAPI accepts BGR and BGRA images, and libjpeg returns RGB order, so we need to revert the pixel order */

	    for (x = 0; x < ( int ) cinfo.output_width; x++) {
	     	r = buffer[0][cinfo.output_components * x];
	      	if (cinfo.output_components > 2) {
	        	g = buffer[0][cinfo.output_components * x + 1];
	        	b = buffer[0][cinfo.output_components * x + 2];
	      	} else {
	        	g = r;
	        	b = r;
	      	}
	      *(dummy++) = b;
	      *(dummy++) = g;
	      *(dummy++) = r;
	    }
	}

	(void) jpeg_finish_decompress(&cinfo);

	/* now create RecognizerImage */
	recognizerImageCreateFromRawImage( &result.recognizerImage, result.imageBuffer, cinfo.output_width, cinfo.output_height, row_stride, RAW_IMAGE_TYPE_BGR );

	jpeg_destroy_decompress(&cinfo);
	fclose(infile);

	return result;
}

void terminateImageWrapper( RecognizerImageWrapper * image ) {
	recognizerImageDelete( &image->recognizerImage );
	free( image->imageBuffer );

	image->recognizerImage = NULL;
	image->imageBuffer	   = NULL;
}
