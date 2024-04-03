#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue
#include <limits> // std::numeric_limits<double>::infinity();

// See point_AABBTree_squared_distance.h for API
typedef std::pair<double, std::shared_ptr<Object> > dist_obj_pair;

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  bool hit = false;
  sqrd = std::numeric_limits<double>::infinity();

  std::priority_queue< dist_obj_pair, std::vector<dist_obj_pair>, std::greater<dist_obj_pair> > queue;
  queue.push(dist_obj_pair(point_box_squared_distance(query, root->box), root));

  dist_obj_pair temp_pair;
  std::shared_ptr<AABBTree> temp_tree;
  double temp_sqrd = 0;

  while(!queue.empty()){
    temp_pair = queue.top();
    queue.pop();

    if(temp_pair.first < sqrd){
      temp_tree = std::dynamic_pointer_cast<AABBTree>(temp_pair.second);
      if(temp_tree != nullptr){
        if(temp_tree->left != nullptr){
          queue.push(dist_obj_pair(point_box_squared_distance(query, temp_tree->left->box), temp_tree->left));
        }
        if(temp_tree->right != nullptr){
          queue.push(dist_obj_pair(point_box_squared_distance(query, temp_tree->right->box), temp_tree->right));
        }
      }

      else{
        temp_sqrd = point_box_squared_distance(query, temp_pair.second->box);
        if(temp_sqrd < sqrd){
          sqrd = temp_sqrd;
          hit = true;
          descendant = temp_pair.second;
        }
      }
    }
  }

  return hit;
  ////////////////////////////////////////////////////////////////////////////
}
