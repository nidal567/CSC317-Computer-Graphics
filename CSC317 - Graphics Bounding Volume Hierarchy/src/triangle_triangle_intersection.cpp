#include "triangle_triangle_intersection.h"

bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  // find max and min of A and B (the x, y, z coordinates)
  //for A
  double A_x_min = std::min({A0(0), A1(0), A2(0)});
  double A_x_max = std::max({A0(0), A1(0), A2(0)});
  double A_y_min = std::min({A0(1), A1(1), A2(1)});
  double A_y_max = std::max({A0(1), A1(1), A2(1)});
  double A_z_min = std::min({A0(2), A1(2), A2(2)});
  double A_z_max = std::max({A0(2), A1(2), A2(2)});

  //for B
  double B_x_min = std::min({B0(0), B1(0), B2(0)});
  double B_x_max = std::max({B0(0), B1(0), B2(0)});
  double B_y_min = std::min({B0(1), B1(1), B2(1)});
  double B_y_max = std::max({B0(1), B1(1), B2(1)});
  double B_z_min = std::min({B0(2), B1(2), B2(2)});
  double B_z_max = std::max({B0(2), B1(2), B2(2)});

  // check if the bounding boxes intersect
  if(A_x_min <= B_x_max && B_x_min <= A_x_max && A_y_min <= B_y_max && 
      B_y_min <= A_y_max && A_z_min <= B_z_max && B_z_min <= A_z_max){
    return true;
  }

  return false; 
  ////////////////////////////////////////////////////////////////////////////
}
