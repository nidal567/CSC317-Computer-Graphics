#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  // Horizontally reflect an image (like a mirror)
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      for (int k = 0; k < num_channels; k++){
        reflected.at(i*width*num_channels + j*num_channels + k) = input.at(i*width*num_channels + (width-1-j)*num_channels + k);
      }
    }
  }
}
