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

#include "Image.h"



Image::Image()
{
}


Image::~Image()
{
}


bool Image::Open(const char * filepath)
{
  b_opened = false;

  image = imread(filepath);
  if (image.data == 0) 
  { 
    printf("Image File Open Error\n"); 
    return false;
  }

  b_opened = true;

  cvtColor(image, gray, COLOR_BGR2GRAY);
  threshold(gray, bin, 127, 255, 0);

  return true;
}


bool Image::SetMemory(int width, int height, unsigned char * data)
{
  b_opened = false;

  try
  {
    image = Mat(height, width, CV_8UC4, (void *)data);
  }
  catch(...)
  {
    return false;
  }
  b_opened = true;

  imwrite("2.png", image);

  cvtColor(image, gray, COLOR_BGR2GRAY);
  threshold(gray, bin, 127, 255, 0);
  return true;
}


bool Image::GetVertex(int(&x)[4], int(&y)[4])
{
  if (b_opened == false) return false;

  int count = 0;
  double p = 0;
  std::vector<Point> vertex;
  std::vector<std::vector<Point>> contours;
  std::vector<Vec4i> hierarchy;
  findContours(bin, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
  if (hierarchy.size() != 0)
  {
    do
    {
      ++p;
      approxPolyDP(contours[0], vertex, p, true);
      // to do exception
    } while (vertex.size() > 4);

    int point_size = vertex.size();
    if (point_size == 4)
    {
      for (int i = 0; i < point_size; ++i)
      {
        x[i] = vertex[i].x;
        y[i] = vertex[i].y;
      }
      return true;
    }
  }
  return false;
}
