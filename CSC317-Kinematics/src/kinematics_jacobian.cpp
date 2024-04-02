#include "kinematics_jacobian.h"
#include "transformed_tips.h"
#include <iostream>

void kinematics_jacobian(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  Eigen::MatrixXd & J)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  // Given a list of Inputs:
  //   b  #b list of indices into skeleton of endpoints to consider
  //   skeleton  #bones list of bones
  // Outputs:
  //   J  #b*3 by #bones*3 Jacobian matrix of partial derivatives. So that
  //     J(i*3+c,j*3+a) = ∂xi,c/∂θj,a where xi,c is the cth component of the ith
  //     endpoint position in b and θj,a is the ath Euler angle in the jth bone.

  const double h = 0.0000001;
  Skeleton copy = skeleton;
  
  Eigen::VectorXd tips = transformed_tips(skeleton, b);  
  Eigen::VectorXd trans_tips;
  
  J = Eigen::MatrixXd::Zero(b.size() * 3, skeleton.size() * 3);

  for (int i = 0; i < skeleton.size(); i ++){
    for (int j = 0; j < 3; j ++){
      copy[i].xzx(j) += h;
      trans_tips = transformed_tips(copy, b);
      copy[i].xzx(j) -= h;  // increment by h and then decrement by h, copy remains unchanged
      J.col(3 * i + j) = (trans_tips - tips) / h;
    }
  }
  /////////////////////////////////////////////////////////////////////////////
}