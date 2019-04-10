#include "Interface.h"

// For c#

// [DllImport("Image.dll", CallingConvention = CallingConvention.Cdecl)]
// static public extern IntPtr Create();
// 
// [DllImport("Image.dll", CallingConvention = CallingConvention.Cdecl)]
// static public extern void Dispose(IntPtr image_ptr);
// 
// [DllImport("Image.dll", CallingConvention = CallingConvention.Cdecl)]
// static public extern bool Open(IntPtr image_ptr, IntPtr filepath);
//
// [DllImport("Image.dll", CallingConvention = CallingConvention.Cdecl)]
// static public extern bool GetVertex(IntPtr image_ptr, IntPtr x, IntPtr y);
// 
// IntPtr image_ptr = IntPtr.Zero; 

// image_ptr = Create();
//
// string path = @"C:\tmp\1.png";
// IntPtr file_path = Marshal.StringToHGlobalAnsi(path);
// Open(image_ptr, file_path);
// Marshal.FreeHGlobal(file_path);
//
// int[] x = new int[4];
// int[] y = new int[4];
// IntPtr x_ptr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(int)) * x.Length);
// IntPtr y_ptr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(int)) * y.Length);
// GetVertex(image_ptr, x_ptr, y_ptr);
//
// Marshal.Copy(x_ptr, x, 0, 4);
// Marshal.Copy(y_ptr, y, 0, 4);
//
// Marshal.FreeHGlobal(x_ptr);
// Marshal.FreeHGlobal(y_ptr);
// Dispose(image_ptr);

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


