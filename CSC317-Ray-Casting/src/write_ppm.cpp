#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <iomanip>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images
  // Want to write an rgb or grayscale image to a ppm file
  std::ofstream ppm_file(filename);

  //From "write_ppm.h" file, if file doesn't open, return false
  if(!ppm_file.is_open()){
   return false;
  }

  //Write an rgb or grayscale image to an ASCII (P2/P3) .ppm file.
  if(num_channels == 3){
    ppm_file << "P3" << "\n";
  }
  if(num_channels == 1){
    ppm_file << "P2" << "\n";
  }
  
  ppm_file << width << " " << height << "\n";
  ppm_file << "255" << "\n";

  //Write data to file
  int count = 0;
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      for(int k=0; k<num_channels; k++){
        int a = data.at(count);
        ppm_file << a;
        count++;
        if(k!=num_channels-1) ppm_file << " ";
      }
      if(j!=width) ppm_file << " ";
    }
    ppm_file << "\n";
  }

  ppm_file.close();
  //if close fails, return false
  if(!ppm_file.close()){
    return false;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
