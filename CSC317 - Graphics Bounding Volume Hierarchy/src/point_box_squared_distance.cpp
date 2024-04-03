#include "point_box_squared_distance.h"
#include <algorithm>

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  
  double distance_x = std::max({box.min_corner(0) - query(0), query(0) - box.max_corner(0), 0.0});
  double distance_y = std::max({box.min_corner(1) - query(1), query(1) - box.max_corner(1), 0.0});
  double distance_z = std::max({box.min_corner(2) - query(2), query(2) - box.max_corner(2), 0.0});

  //return distance_x * distance_x + distance_y * distance_y + distance_z * distance_z;
  // distance^2 = pow(distance_x, 2) + pow(distance_y, 2) + pow(distance_z, 2)
  return (pow(distance_x, 2) + pow(distance_y, 2) + pow(distance_z, 2));
  
  ////////////////////////////////////////////////////////////////////////////
}
