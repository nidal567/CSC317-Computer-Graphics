#include "demosaic.h"
#include <string>

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  // Given a mosaiced image (interleaved GBRG colors in a single channel), create a 3-channel rgb image.
  //std::vector<unsigned char> red(width*height); // R
  //std::vector<unsigned char> green(width*height); // G
  //std::vector<unsigned char> blue(width*height); // B
  std::vector<std::vector<char>> bayerPattern = {{'g', 'b'}, {'r', 'g'}};
  
  // Loop through the image
  // For each pixel, we need neighbouring Bayer pixels
  for(int i = 0; i < height; i++){
    int row_pattern = i%2;
    for(int j = 0; j < width; j++){
      double red = 0, green = 0, blue = 0;
      int red_count = 0, green_count = 0, blue_count = 0;
      int col_pattern = j%2; 
      char colour = bayerPattern[row_pattern][col_pattern];
      int pi = i, pj = j;

      for(int x = pi-1; x<=pi+1; x++){
        for(int y = pj-1; y<=pj+1; y++){
          if(x>=0 && x<height && y>=0 && y<width){
            if(bayerPattern[x%2][y%2] == 'R'){
              red += bayer.at(x*width + y);
              red_count++;
            }
            else if(bayerPattern[x%2][y%2] == 'G'){
              green += bayer.at(x*width + y);
              green_count++;
            }
            else if(bayerPattern[x%2][y%2] == 'B'){
              blue += bayer.at(x*width + y);
              blue_count++;
            }
          }
        }
      }
      // Need to take an average
      unsigned char r = (unsigned char)((int)(red/red_count));
      unsigned char g = (unsigned char)((int)(green/green_count));
      unsigned char b = (unsigned char)((int)(blue/blue_count));

      // Converting Bayer to RGB
      if(colour == 'r'){
        rgb.at(i*width*3 + j*3 + 0) = bayer.at(i*width + j);
        rgb.at(i*width*3 + j*3 + 1) = g;
        rgb.at(i*width*3 + j*3 + 2) = b;
      }
      else if(colour == 'g'){
        rgb.at(i*width*3 + j*3 + 0) = r;
        rgb.at(i*width*3 + j*3 + 1) = bayer.at(i*width + j);
        rgb.at(i*width*3 + j*3 + 2) = b;
      }
      else if(colour == 'b'){
        rgb.at(i*width*3 + j*3 + 0) = r;
        rgb.at(i*width*3 + j*3 + 1) = g;
        rgb.at(i*width*3 + j*3 + 2) = bayer.at(i*width + j);
      }
    }
  }

}
