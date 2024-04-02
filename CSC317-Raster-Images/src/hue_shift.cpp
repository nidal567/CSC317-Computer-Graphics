#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      double h = 0;
      double s = 0;
      double v = 0;
      double r = rgb.at(y*width*3 + x*3 + 0)/255.0;
      double g = rgb.at(y*width*3 + x*3 + 1)/255.0;
      double b = rgb.at(y*width*3 + x*3 + 2)/255.0;

      rgb_to_hsv(r, g, b, h, s, v);
      h = h - shift;
      while(h >= 360.0){
        h -= 360.0;
      }
      while(h < 0.0){
        h += 360.0;
      }
      hsv_to_rgb(h, s, v, r, g, b);
      shifted.at(y*width*3 + x*3 + 0) = (unsigned char)(int)(r*255.0);
      shifted.at(y*width*3 + x*3 + 1) = (unsigned char)(int)(g*255.0);
      shifted.at(y*width*3 + x*3 + 2) = (unsigned char)(int)(b*255.0);
    }
  }
}
