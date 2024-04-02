#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //Convert a 3-channel RGB image to a 1-channel grayscale image
  // 3*W*H -> W*H
  // For every 3rd (last element in rgb), delete it
  for(int i = 0; i<height; i++){
    for(int j = 0; j<width; j++){
      int gray_scale = 0;
      //Formula borrowed from website: 0.2126*r+0.7152*g+0.0722*b
      //setting our RGB values
      int r = rgb.at(i*width*3 + j*3 + 0);
      int g = rgb.at(i*width*3 + j*3 + 1);
      int b = rgb.at(i*width*3 + j*3 + 2);

      gray_scale = 0.2126*r+0.7152*g+0.0722*b;
      gray.at(i*width + j) = gray_scale;
    }
  }
}


