#include "AABBTree.h"
#include "insert_box_into_box.h"

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  if(objects.size() <= 1){
    insert_box_into_box(objects[0]->box, box);
    left = objects[0];
    right = nullptr;
    return;
  }

  int number_of_objects = objects.size();

  for(int i = 0; i < number_of_objects; i++){
    insert_box_into_box(objects[i]->box, box);
  }
  // Construct an axis-aligned bounding box tree given a list of objects. 
  // Use the midpoint along the longest axis of the box containing the 
  // given objects to determine the left-right split

  double x_len = box.max_corner(0) - box.min_corner(0);
  double y_len = box.max_corner(1) - box.min_corner(1);
  double z_len = box.max_corner(2) - box.min_corner(2);
  double max_len = std::max({x_len, y_len, z_len});

  std::vector<std::shared_ptr<Object>> left_objects;
  std::vector<std::shared_ptr<Object>> right_objects;

  // insert objects into left and right vectors
  for(int i = 0; i < number_of_objects; i++){

    if(max_len == x_len){
      if(objects[i]->box.center()(0) <= box.center()(0)){
        left_objects.push_back(objects[i]);}
      else{
        right_objects.push_back(objects[i]);}
    }
    else if(max_len == y_len){
      if(objects[i]->box.center()(1) <= box.center()(1)){
        left_objects.push_back(objects[i]);}
      else{
        right_objects.push_back(objects[i]);}
    }
    else if(max_len == z_len){
      if(objects[i]->box.center()(2) <= box.center()(2)){
        left_objects.push_back(objects[i]);}
      else{
        right_objects.push_back(objects[i]);}
    }

  }
  if(left_objects.size() == 0 && right_objects.size() >= 2){
    left_objects.push_back(right_objects.back());
    right_objects.pop_back();
  }
  if(right_objects.size() == 0 && left_objects.size() >= 2){
    right_objects.push_back(left_objects.back());
    left_objects.pop_back();
  }

  // Construct left and right subtrees
  left = std::make_shared<AABBTree>(left_objects, depth + 1);
  right = std::make_shared<AABBTree>(right_objects, depth + 1);

  ////////////////////////////////////////////////////////////////////////////
}
