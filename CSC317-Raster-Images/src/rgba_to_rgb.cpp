#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  
  //  From Tutorial
  //	Alpha channel: transparency of each pixel location
  //  W*H*4 -> W*H*3
  //  For every 4th (last element in rgba), delete it

  int rgba_count = 0;
  int size = height*width*3;

  for(int i=0; i<size; i++){
  	rgb.at(i) = rgba.at(rgba_count);
  	rgba_count++;
  	if((i+1)%3==0){
      rgba_count++;
    }
  }
}
