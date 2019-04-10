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

  image = cv::imread(filepath);
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


bool Image::GetVertex(int(&x)[4], int(&y)[4])
{
  if (b_opened == false) return false;

  int count = 0;
  double p = 0;
  std::vector<Point> vertex;
  std::vector<std::vector<Point>> contours;
  std::vector<Vec4i> hierarchy;
  findContours(bin, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
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
  return false;
}
