#include "euler_angles_to_transform.h"

Eigen::Affine3d euler_angles_to_transform(
  const Eigen::Vector3d & xzx)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  // Construct a rotation matrix (as a 4x4 transformation) given a set of Euler
  // angles.
  //
  // Inputs:
  //   xzx  3-vector of extrinsic Euler angles rotating about the x-, z-, and
  //     x-axes.
  // Returns 3d Eigen Affine transformation.

  return (Eigen::Affine3d) Eigen::AngleAxisd(M_PI * xzx(2) / 180, Eigen::Vector3d::UnitX()) *
                          Eigen::AngleAxisd(M_PI * xzx(1) / 180, Eigen::Vector3d::UnitZ()) *
                          Eigen::AngleAxisd(M_PI * xzx(0) / 180, Eigen::Vector3d::UnitX());
  /////////////////////////////////////////////////////////////////////////////
}