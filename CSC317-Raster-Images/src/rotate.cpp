#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //Rotate an image 90 degrees counter-clockwise
  //Triple for-loop, how would I go about 2 for-loops?
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      for(int k=0; k<num_channels; k++){
        rotated.at(i*width*num_channels + j*num_channels + k) = input.at((height-1-i)*width*num_channels + j*num_channels + k);
      }
    }
  }
}
