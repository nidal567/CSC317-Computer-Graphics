#include "projected_gradient_descent.h"
#include "line_search.h"

void projected_gradient_descent(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<Eigen::VectorXd(const Eigen::VectorXd &)> & grad_f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const int max_iters,
  Eigen::VectorXd & z)
{
  /////////////////////////////////////////////////////////////////////////////
  // Add your code here

  // Conduct `max_iters` iterations of projected gradient descent.
  //
  // Inputs:
  //   f  function that computes scalar objective value at a given z
  //   grad_f  function that computes gradient of f with respect to z at a given z
  //   proj_z  function that projects z onto the set of feasible values
  //   z  #z vector of initial z values
  // Outputs
  //   z  #z vector of optimized z values

  const double max_step = 100.0;
  for (int i = 0; i < max_iters; i++){
      Eigen::VectorXd delta_z = grad_f(z);
      double step = line_search(f, proj_z, z, delta_z, max_step);
      z = z - step * delta_z;
      proj_z(z);
  }
  /////////////////////////////////////////////////////////////////////////////
}