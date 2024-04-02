#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Intersect a plane with a ray.
  // From lecture slides
  // Setting up formulas for discriminant
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d p = point;
  Eigen::Vector3d n = normal;
  n = n.normalized();

  // From lecture slides
  // If ray is parallel to plane, then no intersection
  if(d.dot(n) == 0){
    return false;
  }

  // From lecture slides
  // note that t = -(e - p) dot n / d dot n
  // -(e - p) dot n = (p - e) dot n (property)
  double temp_t = (p - e).dot(n) / d.dot(n);
  if(temp_t < 0){
    return false;
  }
  else if(temp_t >= 0 && temp_t < min_t){
    return false;
  }
  else{
    t = temp_t;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

