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
// static public extern bool SetMemory(IntPtr image_ptr, int w, int h, IntPtr data);
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
// int pixel_w = img.PixelWidth;
// int pixel_h = img.PixelHeight;
// int pixel_bpp = img.Format.BitsPerPixel;
// int stride = (int)pixel_w * (pixel_bpp / 8);
// int pixel_size = (int)pixel_h * stride;
// byte[] pixels = new byte[pixel_size];
// img.CopyPixels(pixels, stride, 0);
// IntPtr pixel_ptr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(byte)) * pixel_size);
// Marshal.Copy(pixels, 0, pixel_ptr, pixel_size);
// SetMemory(image_ptr, img.PixelWidth, img.PixelHeight, pixel_ptr);
// Marshal.FreeHGlobal(pixel_ptr);
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

bool SetMemory(Image* image_ptr, int w, int h, unsigned char * data)
{
  if (image_ptr != nullptr)
  {
    return image_ptr->SetMemory(w, h, data);
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


