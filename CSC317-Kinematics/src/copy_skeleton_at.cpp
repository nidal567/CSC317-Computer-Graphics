#include "copy_skeleton_at.h"
Skeleton copy_skeleton_at(
  const Skeleton & skeleton, 
  const Eigen::VectorXd & A)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  // Copy a given skeleton with joint angles set to those in vector A.
  // Inputs:
  //   skeleton  input skeleton
  //   A  #bones*3 list of Euler angles
  // Returns a skeleton copy

  Skeleton copy = skeleton;

  for (int i = 0; i < skeleton.size(); i++) {
      copy[i].xzx.x() = A(3*i+0);
      copy[i].xzx.y() = A(3*i+1);
      copy[i].xzx.z() = A(3*i+2);
  }

  return copy;
  /////////////////////////////////////////////////////////////////////////////
}
