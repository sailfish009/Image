#pragma once

#include "Image.h"

Image* Create();

void Dispose(Image* image_ptr);

bool Open(Image* image_ptr, const char* filepath);

bool GetVertex(Image* image_ptr, int(&x)[4], int(&y)[4]);

