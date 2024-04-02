#include "PointLight.h"

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  d = this->p - q;
  max_t = d.norm();
  d = d.normalized();
  return;
  ////////////////////////////////////////////////////////////////////////////
}