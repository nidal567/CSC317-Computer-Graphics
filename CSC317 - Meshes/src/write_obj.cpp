#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::ofstream objfile(filename);

  if(!objfile.is_open()){
    return false;
  }

  int numV = V.rows();
  for(int i = 0; i < numV; i++){
    objfile<< "v " << V(i,0) << " " << V(i,1) << " " << V(i,2) << std::endl;
  }

  int num3d_normal = NV.rows();
  for(int i = 0; i < num3d_normal; i++){
    objfile<< "vn " << NV(i,0) << " " << NV(i,1) << " " << NV(i,2) << std::endl;
  }

  int num2d_normal = UV.rows();
  for(int i = 0; i < num2d_normal; i++){
    objfile<< "vt " << UV(i,0) << " " << UV(i,1) << std::endl;
  }

  for (int i = 0; i < F.rows(); i++) {
        objfile << "f ";
        for (int j = 0; j < F.cols(); j++) {
            objfile << F(i, j)+1 << "/" << UF(i, j)+1 << "/" << NF(i, j)+1 << " ";
        }
        objfile << "\n";
    }

    // if close fails, return false.
    objfile.close();
    if (!objfile){
        return false;
    }
    return true;

  ////////////////////////////////////////////////////////////////////////////
  return false;
}
