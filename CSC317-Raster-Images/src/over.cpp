#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int read_A = 0;
  int read_B = 0;
  int write = 0;

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      // Semi-transparent RGBA image "A"
      double A_r = A.at(4*(y*width+x) + 0)/255.0;
      double A_g = A.at(4*(y*width+x) + 1)/255.0;
      double A_b = A.at(4*(y*width+x) + 2)/255.0;
      double A_a = A.at(4*(y*width+x) + 3)/255.0;
      // Semi-transparent RGBA image "B"
      double B_r = B.at(4*(y*width+x) + 0)/255.0;
      double B_g = B.at(4*(y*width+x) + 1)/255.0;
      double B_b = B.at(4*(y*width+x) + 2)/255.0;
      double B_a = B.at(4*(y*width+x) + 3)/255.0;

      // Compute C = A Over B, where A and B are semi-transparent rgba images and "Over" is the Porter-Duff Over operator.
      // https://en.wikipedia.org/wiki/Alpha_compositing#Alpha_blending
      double Porter_Duff_a = 1.0 - (1.0 - A_a) * (1.0 - B_a);
      double Porter_Duff_r = ((A_a * A_r) + (1.0 - A_a) * B_a * B_r) / Porter_Duff_a;
      double Porter_Duff_g = ((A_a * A_g) + (1.0 - A_a) * B_a * B_g) / Porter_Duff_a;
      double Porter_Duff_b = ((A_a * A_b) + (1.0 - A_a) * B_a * B_b) / Porter_Duff_a;

      C.at(4*(y*width+x) + 0) = (unsigned char)(int)(Porter_Duff_r*255.0);
      C.at(4*(y*width+x) + 1) = (unsigned char)(int)(Porter_Duff_g*255.0);
      C.at(4*(y*width+x) + 2) = (unsigned char)(int)(Porter_Duff_b*255.0);
      C.at(4*(y*width+x) + 3) = (unsigned char)(int)(Porter_Duff_a*255.0);
    }
  }
}
