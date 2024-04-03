#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  bool hit = false;

  //If there's one leaf in the tree, return the intersect of the leaf
  if (num_leaves == 1){
    if (left->ray_intersect(ray, min_t, max_t, t, descendant)){
      descendant = this->left;
      hit = true;
    }
    return hit;
  }

  //Check ray intersect with the box of the tree
  bool temp_left_intersect = ray_intersect_box(ray, left->box, min_t, max_t);
  bool temp_right_intersect = ray_intersect_box(ray, right->box, min_t, max_t);

  if(temp_left_intersect && temp_right_intersect){
    double t_left;
    double t_right;
    std::shared_ptr<Object> descendant_left;
    std::shared_ptr<Object> descendant_right;
    bool left_intersect = this->left->ray_intersect(ray, min_t, max_t, t_left, descendant_left);
    bool right_intersect = this->right->ray_intersect(ray, min_t, max_t, t_right, descendant_right);
    
    //If both left and right intersect, return the intersect with smaller t
    if (left_intersect && right_intersect){
      //If left intersect with smaller t, return left intersect
      if (t_left < t_right){
        t = t_left;
        descendant = descendant_left;
      }
      //If right intersect with smaller t, return right intersect
      else{
        t = t_right;
        descendant = descendant_right;
      }
      hit = true;
    }
    else if (left_intersect && !right_intersect){
      t = t_left;
      descendant = descendant_left;
      hit = true;
    }
    else if (right_intersect && !left_intersect){
      t = t_right;
      descendant = descendant_right;
      hit = true;
    }
    //If both left and right don't intersect, return false
    else{
      hit = false;
    }
  }
  else if (temp_left_intersect && !temp_right_intersect){
    hit = this->left->ray_intersect(ray, min_t, max_t, t, descendant);
  }
  else if (temp_right_intersect && !temp_left_intersect){
    hit = this->right->ray_intersect(ray, min_t, max_t, t, descendant);
  }

  return hit;
  ////////////////////////////////////////////////////////////////////////////
}

