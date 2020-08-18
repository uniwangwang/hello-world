#pragma once

#ifdef TIFF_DEMO_EXPORTS
#define TIFF_DEMO_API  __declspec(dllexport)
#else
#define TIFF_DEMO_API  __declspec(dllimport)
#endif

#ifndef TIFF_DEMO_H
#define TIFF_DEMO_H

//#include "..\Tiff_demo\pch.h"
#include "tiffio.h"
#include<iostream>

 class TIFF_DEMO_API tiffC {

public:
	TIFF *image;
	

// Open the TIFF file

	

tiffC();

bool tiffc_Open(const char * str);

void set_tiff(int width,int height);

// Write the information to the file and close
bool tiffc_Write_Close(char* buffer, int width, int height);

int file_size(const char* filename);


};


#endif //PCH_H