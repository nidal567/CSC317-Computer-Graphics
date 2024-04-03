#include "ray_intersect_triangle.h"
#include <Eigen/Geometry>
#include <vector>


bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //tolerance
  double epsilon = 0.001;
  // Ray: origin e, direction d
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  // Triangle: A, B, C
  Eigen::Vector3d a = A;
  Eigen::Vector3d b = B;
  Eigen::Vector3d c = C;
  // triangle lines between corners: ab, ac, bc
  Eigen::Vector3d ab = a - b;
  Eigen::Vector3d ac = a - c;
  Eigen::Vector3d bc = b - c;

  // unit normal vector of triangle
  Eigen::Vector3d n = ab.cross(bc) / (ab.cross(bc)).norm();

  // find smallest t, but must be larger than min_t
  double ta = (n.dot(a) - n.dot(e)) / (n.dot(d));
  double tb = (n.dot(b) - n.dot(e)) / (n.dot(d));
  double tc = (n.dot(c) - n.dot(e)) / (n.dot(d));
  std::vector<double> t_list = {ta, tb, tc};
  std::sort(t_list.begin(), t_list.end()); // sort t_list in order (smallest to largest)
  if(t_list[0] >= min_t){
    t = t_list[0];
  }
  else if(t_list[1] >= min_t){
    t = t_list[1];
  }
  else if(t_list[2] >= min_t){
    t = t_list[2];
  }
  else{
    return false;
  }

  // verify whether the intersection point is within tolerance range
  Eigen::Vector3d p = e + t * d;
  Eigen::Vector3d ap = a - p;
  Eigen::Vector3d bp = b - p;
  Eigen::Vector3d cp = c - p;

  double offset = abs(ap.cross(bp).norm() + bp.cross(cp).norm() + cp.cross(ap).norm() - ab.cross(bc).norm());
  if(1 - epsilon < offset && offset < 1 + epsilon){
    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

