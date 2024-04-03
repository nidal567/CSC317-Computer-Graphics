#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Compute the nearest neighbor for a query in the 
  // set of n points (rows of points)

  double temp_sqrD = std::numeric_limits<double>::infinity();
  sqrD = std::numeric_limits<double>::infinity();
  int I = -1;
  
  //given in the assignment the value of I should be -1 if the set of points is empty ^^

  // find smallest distance
  for (int i = 0; i < points.rows(); i++){
    //compute the distance between the query and the point
    // double temp_sqrD = (points.row(i) - query).norm();
    // aka distance^2 = (point - query)^2
    temp_sqrD = (points.row(i) - query).squaredNorm();
    if (temp_sqrD < sqrD){
      sqrD = temp_sqrD;
      I = i;
    }
  }

  return;
  ////////////////////////////////////////////////////////////////////////////
}
