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

  cvtColor(image, gray, COLOR_BGR2GRAY);
  threshold(gray, bin, 127, 255, 0);
  return true;
}


bool Image::GetVertex(int(&x)[4], int(&y)[4])
{
  if (b_opened == false) return false;

  int count = 0;
  std::vector<std::vector<Point>> contours;
  std::vector<Vec4i> hierarchy;
  findContours(bin, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
  // even if in this case, have to chack valid range of vertex points.
  if ( (contours.size() > 0) && (hierarchy.size() > 0) )
  {
    std::vector<Point> vertex;
    double epsilon = 1;
    approxPolyDP(Mat(contours[0]), vertex, epsilon, true);
    if (vertex.size() >= 4)
    {
      std::vector<int> vec_x;
      std::vector<int> vec_y;
      for (size_t i = 0; i < vertex.size(); ++i)
      {
        vec_x.push_back(vertex[i].x);
        vec_y.push_back(vertex[i].y);
      }
      double min_x = *std::min_element(vec_x.begin(), vec_x.end());
      double max_x = *std::max_element(vec_x.begin(), vec_x.end());
      double min_y = *std::min_element(vec_y.begin(), vec_y.end());
      double max_y = *std::max_element(vec_y.begin(), vec_y.end());

      x[0] = min_x; y[0] = min_y;
      x[1] = max_x; y[1] = min_y;
      x[2] = max_x; y[2] = max_y;
      x[3] = min_x; y[3] = max_y;

      // Point p1 = Point(min_x, min_y);
      // Point p2 = Point(max_x, max_y);
      // rectangle(drawing, p1, p2, Scalar(0, 0, 255));
      return true;
    }
  }
  return false;
}
