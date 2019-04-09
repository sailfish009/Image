#include "Interface.h"

// For c#

// [DllImport("Image.dll")]
// static public extern IntPtr Create();
// 
// [DllImport("Image.dll")]
// static public extern void Dispose(IntPtr image_ptr);
// 
// [DllImport("Image.dll")]
// static public extern bool Open(IntPtr image_ptr, IntPtr filepath);
//
// [DllImport("Image.dll")]
// static public extern bool GetVertex(IntPtr image_ptr, IntPtr x, IntPtr y);
// 
// IntPtr image_ptr = IntPtr.Zero; 


Image* Create()
{
  return new Image();
}

void Dispose(Image* image_ptr)
{
  if (image_ptr != nullptr)
  {
    delete image_ptr;
    image_ptr = nullptr;
  }
}

bool Open(Image* image_ptr, const char * filepath)
{
  if (image_ptr != nullptr)
  {
    return image_ptr->Open(filepath);
  }
  return false;
}

bool GetVertex(Image* image_ptr, int (&x)[4], int (&y)[4])
{
  if (image_ptr != nullptr)
  {
    return image_ptr->GetVertex(x, y);
  }
  return false;
}


