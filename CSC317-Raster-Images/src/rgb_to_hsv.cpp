#include "rgb_to_hsv.h"
#include <algorithm>
#include <functional>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  ////////////////////////////////////////////////////////////////////////////

  // Convert a color represented by red, green and blue intensities to its
  // representation using hue, saturation and value.
  // The hue should be in the range 0-360 degrees, saturation and value in the
  // range 0-1. If the color is achromatic (has no saturation), set hue to 0.
  double rgb_values[3] = {r, g, b};
  std::sort(rgb_values, rgb_values+3, std::greater<double>());
  double max = rgb_values[0];
  double min = rgb_values[2];
  double delta = max - min;

  // https://www.rapidtables.com/convert/color/rgb-to-hsv.html
  // Helped with figuring out formulas: https://www.geeksforgeeks.org/program-change-rgb-color-model-hsv-color-model/
  if(max == min){
    h = 0;
  } else if(max == r && g >= b){
    h = 60*(g-b)/delta;
  } else if(max == r && g < b){
    h = 60*(g-b)/delta + 360;
  } else if(max == g){
    h = 60*(b-r)/delta + 120;
  } else if(max == b){
    h = 60*(r-g)/delta + 240;
  }
  if(max == 0){
    s = 0;
  } else{
    s = delta/max;
  }
  v = max;
}
