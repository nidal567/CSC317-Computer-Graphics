#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  // Find all intersecting pairs of leaf boxes between one AABB tree and another
  // AABB tree. Use a list as a queue.
  // linked list of pairs of nodes
  std::list<std::pair<std::shared_ptr<AABBTree>, std::shared_ptr<AABBTree>>> list;

  // temporary pair of nodes and temporary pair of objects
  std::shared_ptr<AABBTree> tempNodeA;
  std::shared_ptr<AABBTree> tempNodeB;

  if(box_box_intersect(rootA->box, rootB->box)){
    list.emplace_back(rootA, rootB);
  }

  // while the list is not empty (used as a queue)
  while(!list.empty()){
    tempNodeA = list.front().first;
    tempNodeB = list.front().second;
    list.pop_front();

    // if both nodes are leaves, add the pair of objects to the vector
    // check if the boxes of the two nodes intersect
    // if they do, add the pair of nodes to the list
    if(tempNodeA->num_leaves <= 1 && tempNodeB->num_leaves <= 1){
      if(box_box_intersect(tempNodeA->left->box, tempNodeB->left->box)){
        leaf_pairs.emplace_back(tempNodeA->left, tempNodeB->left);
      }
    }
    
    // else case for check intersection between nodeA box with nodeB
    else if(tempNodeA->num_leaves <= 1 && tempNodeB->num_leaves > 1){
      if(box_box_intersect(tempNodeA->box, tempNodeB->left->box)){
        list.emplace_back(tempNodeA, std::dynamic_pointer_cast<AABBTree>(tempNodeB->left));
      }
      if(box_box_intersect(rootA->box, rootB->right->box)){
        list.emplace_back(tempNodeA, std::dynamic_pointer_cast<AABBTree>(tempNodeB->right));
      }
    }
    
    // other case vice versa
    else if(tempNodeA->num_leaves > 1 && tempNodeB->num_leaves <=1){
      if(box_box_intersect(tempNodeA->left->box, tempNodeB->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->left), tempNodeB);
      }
      if(box_box_intersect(tempNodeA->right->box, tempNodeB->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->right), tempNodeB);
      }
    }

    else {
      if(box_box_intersect(tempNodeA->left->box, tempNodeB->left->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->left), std::dynamic_pointer_cast<AABBTree>(tempNodeB->left));
      }
      if(box_box_intersect(tempNodeA->left->box, tempNodeB->right->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->left), std::dynamic_pointer_cast<AABBTree>(tempNodeB->right));
      }
      if(box_box_intersect(tempNodeA->right->box, tempNodeB->left->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->right), std::dynamic_pointer_cast<AABBTree>(tempNodeB->left));
      }
      if(box_box_intersect(tempNodeA->right->box, tempNodeB->right->box)){
        list.emplace_back(std::dynamic_pointer_cast<AABBTree>(tempNodeA->right), std::dynamic_pointer_cast<AABBTree>(tempNodeB->right));
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
