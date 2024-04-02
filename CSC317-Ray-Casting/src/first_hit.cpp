#include "first_hit.h"
#include <limits>

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Find the first (visible) hit given a ray and a collection of scene objects
  // Initializing time to infinity
  double min_t_tmp = std::numeric_limits<double>::max();
  int num_objects = objects.size();
  int surface_flag = 0;
  int temp_id;
  Eigen::Vector3d temp_normal;

  for(int i = 0; i < num_objects; i++){
    double temp_t;
    Eigen::Vector3d current_n;
    bool hit = objects[i]->intersect(ray, min_t, temp_t, current_n);
    if(hit){
      if(temp_t < min_t_tmp){
        min_t_tmp = temp_t;
        temp_id = i;
        temp_normal = current_n;
        surface_flag = 1;
      }
    }
  }

  if(surface_flag == 1){
    hit_id = temp_id;
    t = min_t_tmp;
    n = temp_normal;
    return true;
  }
  else{
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}

