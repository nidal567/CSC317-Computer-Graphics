#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function

void forward_kinematics(
  const Skeleton & skeleton,
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  // Compute the deformations (tranformations from rest pose) for each node in a
  // forward kinematics hiearchy (reading each node's relative transformation from
  // rest).
  //
  // Inputs:
  //   skeleton  transformation hierarchy of #T bones
  // Outputs:
  //   T  #T list of affine transformations

  T.resize(skeleton.size(),Eigen::Affine3d::Identity());
  for (int i = 0; i < skeleton.size(); i++){
    if (skeleton[i].parent_index == -1){  // root node
      T[i] = Eigen::Affine3d::Identity();
    }
    else{  // children / non-root nodes
      T[i] = T[skeleton[i].parent_index] * skeleton[i].rest_T * euler_angles_to_transform(skeleton[i].xzx) * skeleton[i].rest_T.inverse();
    }
  }
  /////////////////////////////////////////////////////////////////////////////
}