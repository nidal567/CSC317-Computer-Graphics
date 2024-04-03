#include "sphere.h"
#include <iostream>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:

  V.resize((num_faces_u+1)*(num_faces_v+1),3);
  UV.resize((num_faces_u+1)*(num_faces_v+1),2);
  NV.resize((num_faces_u+1)*(num_faces_v+1),3);
  F.resize(num_faces_u*num_faces_v, 4);
  UF.resize(num_faces_u*num_faces_v, 4);
  NF.resize(num_faces_u*num_faces_v, 4);


  for(int i = 0; i <= num_faces_u; i++){
    for(int j = 0; j <= num_faces_v; j++){
      int idx = i*(num_faces_v+1) + j;
      double u = ((double)i/num_faces_u - 0.5)*((2*M_PI));  //longitute
      double v = ((double)j/num_faces_v - 0.5)*((M_PI));    //latitude

      double x = cos(u)*cos(v);
      double y = sin(u)*cos(v);
      double z = sin(v);

      V.row(idx) = Eigen::RowVector3d(x, y, z);
      UV.row(idx) = Eigen::RowVector2d((double)i/num_faces_u, (double)j/num_faces_v);
      NV.row(idx) = Eigen::RowVector3d(x, y, z);
    }
  }

  int index = 0;
  for(int i = 0; i < num_faces_u; i++){
    for(int j = 0; j < num_faces_v; j++){
      int idx = i*(num_faces_v+1) + j;
      F.row(index) = Eigen::RowVector4i(idx, idx+1, idx+num_faces_v+2, idx+num_faces_v+1);
      UF.row(index) = Eigen::RowVector4i(idx, idx+1, idx+num_faces_v+2, idx+num_faces_v+1);
      NF.row(index) = Eigen::RowVector4i(idx, idx, idx, idx);
      index++;
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
