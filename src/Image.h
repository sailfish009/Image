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
  bool Image::GetVertex(int(&x)[4], int(&y)[4]);

};

