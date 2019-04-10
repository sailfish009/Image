#pragma once

#include "Image.h"

extern "C" Image* Create();

extern "C" void Dispose(Image* image_ptr);

extern "C" bool Open(Image* image_ptr, const char* filepath);

extern "C" bool GetVertex(Image* image_ptr, int(&x)[4], int(&y)[4]);

