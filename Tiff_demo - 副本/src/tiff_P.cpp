#include "pch.h"
#include "..\include\Tiff_demo.h"
#include <fstream>
#include <iostream>


tiffC::tiffC() {
	image = nullptr;

}

bool tiffC::tiffc_Open(const char * str) {
	if ((image = TIFFOpen(str, "w")) == NULL) {
		exit(42);
	}

	else
		return  true;

}

void tiffC::set_tiff(int width, int height) {
	//TIFFSetField(image, TIFFTAG_IMAGEWIDTH, width * 8);   /* image width in pixels */
	TIFFSetField(image, TIFFTAG_IMAGEWIDTH, width );
	TIFFSetField(image, TIFFTAG_IMAGELENGTH, height);     /* image height in pixels */
	TIFFSetField(image, TIFFTAG_BITSPERSAMPLE, 1);     /* bits per channel (sample) */
	TIFFSetField(image, TIFFTAG_SAMPLESPERPIXEL, 1);   /* samples per pixel */
	TIFFSetField(image, TIFFTAG_ROWSPERSTRIP, height); 	/* rows per strip of data */

	TIFFSetField(image, TIFFTAG_COMPRESSION, COMPRESSION_CCITTFAX4);
	TIFFSetField(image, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISWHITE);
	TIFFSetField(image, TIFFTAG_FILLORDER, FILLORDER_MSB2LSB);
	TIFFSetField(image, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);

	TIFFSetField(image, TIFFTAG_XRESOLUTION, 150);  /* pixels/resolution in x */
	TIFFSetField(image, TIFFTAG_YRESOLUTION, 150);  /* pixels/resolution in y */
	TIFFSetField(image, TIFFTAG_RESOLUTIONUNIT, RESUNIT_INCH); /* units of resolutions */  /* english */



}

bool tiffC::tiffc_Write_Close(char* buffer, int width, int height) {
	// Write the information to the file
	TIFFWriteEncodedStrip(image, 0, buffer, width * height);

	// Close the file
	TIFFClose(image);

	return true;
}


//需要先执行 tiffC::tiffc_Write_Close。 关闭之后在 使用该函数
//获取输出的tiff文件的大小
int tiffC::file_size(const char* filename) 
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "r");
	if (!fp) return -1;
	fseek(fp, 0L, SEEK_END);
	int size = ftell(fp);
	fclose(fp);

	return size;
}