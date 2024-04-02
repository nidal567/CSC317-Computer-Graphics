#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  //  Bayer pattern:
  //  G B
  //  R G
  std::vector<std::vector<char>> bayerPattern = {{'g', 'b'}, {'r', 'g'}};
  int count = 0;
  for(int i = 0; i < height; i++){
    int row_pattern = i%2;
    for(int j = 0; j < width; j++){
      int col_pattern = j%2; 
      
      char colour = bayerPattern[row_pattern][col_pattern];
      // Converting RGB to Bayer
      if(colour == 'r'){
        bayer.at(i*width + j) = rgb.at(i*width*3 + j*3 + 0);
      }
      else if(colour == 'g'){
        bayer.at(i*width + j) = rgb.at(i*width*3 + j*3 + 1);
      }
      else if(colour == 'b'){
        bayer.at(i*width + j) = rgb.at(i*width*3 + j*3 + 2);
      }
    }
  }
}
