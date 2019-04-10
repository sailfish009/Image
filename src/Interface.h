//========================================================================
// Image - OpenCV Wrapper DLL
//------------------------------------------------------------------------
// Copyright (c) 2019 Ji Wong Park <sailfish009@gmail.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#pragma once

#include "Image.h"

extern "C" Image* Create();

extern "C" void Dispose(Image* image_ptr);

extern "C" bool Open(Image* image_ptr, const char* filepath);

extern "C" bool SetMemory(Image* image_ptr, int w, int h, unsigned char * data);

extern "C" bool GetVertex(Image* image_ptr, int(&x)[4], int(&y)[4]);

