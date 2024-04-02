#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <algorithm>
#include <Eigen/Geometry>


bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Intersect a sphere with a ray.
  
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d c = center;

  //From lecture slides
  //Setting up formulas for discriminant
  double a = d.dot(d);
  double b = 2 * d.dot(e - c);
  //radius * radius same as pow(radius, 2)
  double c = (e - c).dot(e - c) - radius * radius;
  double discriminant = b * b - 4 * a * c;

  if(discriminant < 0){
    return false;
  }
  //if tangent to sphere surface
  else if(discriminant <= 0.0001){
    double temp_t = -b / (2 * a);
    if(temp_t > min_t){
      t = temp_t;
      n = (e + t * d - c)/radius;
      n = n.normalized();
      return true;
    }
    return false;
  }

  //if there exists two solutions, then we need to find if eye exists inside or outside the sphere
  double temp_t1 = (-b + sqrt(discriminant)) / (2 * a);
  double temp_t2 = (-b - sqrt(discriminant)) / (2 * a);

  //if both solutions are greater than min_t, then we need to find if eye exists inside or outside the sphere
  if(temp_t1 > min_t && temp_t2 > min_t){
    //if eye is outside the sphere
    if((e - c).dot(e - c) > radius * radius){
      t = std::min(temp_t1, temp_t2);
      n = (e + t * d - c)/radius;
      n = n.normalized();
      return true;
    }
    //if eye is inside the sphere
    else{
      t = std::max(temp_t1, temp_t2);
      n = (e + t * d - c)/radius;
      n = n.normalized();
      return true;
    }
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

