#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  bool hit = false;
  bool temp_intersect = false;
  Eigen::RowVector3d A, B, C;
  double temp_t = std::numeric_limits<double>::infinity();
  hit_t = std::numeric_limits<double>::infinity();
  hit_f = 0;

  //Check if the ray intersect with any triangle in the mesh
  for (int i = 0; i < F.rows(); i++){
    A = V.row(F(i, 0));
    B = V.row(F(i, 1));
    C = V.row(F(i, 2));
    temp_intersect = ray_intersect_triangle(ray, A, B, C, min_t, max_t, temp_t);
    if (temp_intersect && temp_t < hit_t){
      hit = true;
      hit_t = temp_t;
      hit_f = i;
    }
  }
  return hit;
  ////////////////////////////////////////////////////////////////////////////
}
