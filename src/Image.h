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

#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui_c.h>

#pragma comment(lib, "opencv_core401d.lib" )
#pragma comment(lib, "opencv_imgproc401d.lib" )
#pragma comment(lib, "opencv_highgui401d.lib" )
#pragma comment(lib, "opencv_videoio401d.lib" )
#pragma comment(lib, "opencv_imgcodecs401d.lib" )

using namespace cv;

class Image
{
public:
  Image();
  ~Image();

private:
  bool b_opened = false;
  Mat image;
  Mat bin;
  Mat gray;

public:
  bool Open(const char* filepath);
  bool SetMemory(int width, int height, unsigned char * data);
  bool GetVertex(int(&x)[4], int(&y)[4]);

};

