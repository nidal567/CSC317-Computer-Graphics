#include "Triangle.h"
#include "Ray.h"
#include <iostream>
#include <Eigen/Geometry>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Intersect a triangle with a ray.
  Eigen::Vector3d a = std::get<0>(corners);
  Eigen::Vector3d b = std::get<1>(corners);
  Eigen::Vector3d c = std::get<2>(corners);
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;

  Eigen::Vector3d first_column = a - b; //vector from a to b
  Eigen::Vector3d second_column = a - c; //vector from a to c
  Eigen::Vector3d right_side = a - e; //vector from a to e

  //direction fector
  Eigen:Vector3d dir;

  double A = first_column(0);
  double B = first_column(1);
  double C = first_column(2);

  double D = second_column(0);
  double E = second_column(1);
  double F = second_column(2);

  double G = d(0);
  double H = d(1);
  double I = d(2);

  double J = right_side(0);
  double K = right_side(1);
  double L = right_side(2);

  //From lecture slides
  //Setting up formulas
  double M = A * (E * I - H * F) + B * (G * F - D * I) + C * (D * H - E * G);

  double beta = (J * (E * I - H * F) + K * (G * F - D * I) + L * (D * H - E * G)) / M;
  double gamma = (I * (A * K - J * B) + H * (J * C - A * L) + G * (B * L - K * C)) / M;
  double temp_t = -(F * (A * K - J * B) + E * (J * C - A * L) + D * (B * L - K * C)) / M;

  if(temp_t < min_t){
    return false;
  }
  else if(beta < 0 || beta > 1){
    return false;
  }
  else if(gamma < 0 || gamma > 1){
    return false;
  }
  //if beta + gamma > 1, then the point is outside the triangle
  //if beta + gamma < 1, then the point is inside the triangle
  // beta > (1-gamma) and beta + gamma < 1 are equivalent
  else if(beta + gamma > 1){
    return false;
  }
  else{
    t = temp_t;
    dir = (first_column).cross(second_column);
    n = dir/sqrt(dir.dot(dir));
    return true;
  }

  ////////////////////////////////////////////////////////////////////////////
}


