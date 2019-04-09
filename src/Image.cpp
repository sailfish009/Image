#include "Image.h"



Image::Image()
{
}


Image::~Image()
{
}


bool Image::Open(const std::string& filepath)
{
  b_opened = false;

  image = cv::imread(filepath.c_str());
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


bool Image::GetVertex(std::vector<Point>& v)
{
  if (b_opened == false) return false;

  double p = 0;
  std::vector<std::vector<Point>> contours;
  std::vector<Vec4i> hierarchy;
  findContours(bin, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
  do
  {
    ++p;
    approxPolyDP(contours[0], v, p, true);
  } while (v.size() > 4);
  return true;
}
