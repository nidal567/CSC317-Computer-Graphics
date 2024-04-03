#include "box_box_intersect.h"


bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  
  // delta between the max and min of A and B respectively
  Eigen::RowVector3d delta_AB = A.max_corner - B.min_corner;
  Eigen::RowVector3d delta_BA = B.max_corner - A.min_corner;

  // if any of the delta is negative, then there is no intersection
  if(delta_AB(0) >= 0 && delta_AB(1) >= 0 && delta_AB(2) >= 0 &&
      delta_BA(0) >= 0 && delta_BA(1) >= 0 && delta_BA(2) >= 0){
    return true;
  }
  
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

