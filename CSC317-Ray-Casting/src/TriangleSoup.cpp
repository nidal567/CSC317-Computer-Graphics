#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Intersect a triangle soup with a ray.
  int hit_id;
  bool hit = first_hit(ray, min_t, triangles, hit_id, t, n);
  return hit;
  ////////////////////////////////////////////////////////////////////////////
}



