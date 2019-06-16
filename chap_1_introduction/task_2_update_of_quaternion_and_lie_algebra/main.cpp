#include <iostream>
#include <Eigen/Dense>
#include "sophus/so3.h"

int main()
{
    Eigen::Matrix3d orientation_in_mat(Eigen::Matrix3d::Identity());
    Eigen::Quaterniond orientation_in_quat(Eigen::Quaterniond::Identity());

    Eigen::Vector3d update_in_so3(0.01, 0.02, 0.03);
    Eigen::Quaterniond update_in_quat(1, 0.01/2, 0.02/2, 0.03/2);
    update_in_quat.normalize();

    int it_num = 20;
    for(int i = 0; i < it_num; i++)
    {
        orientation_in_mat = Sophus::SO3::exp(update_in_so3).matrix() * orientation_in_mat;
        orientation_in_quat = update_in_quat * orientation_in_quat;
        std::cout << "step" << i << ": ";
        std::cout << "quat: " << orientation_in_quat.coeffs().transpose() << "\t\t";
        std::cout << "mat: " << Eigen::Quaterniond(orientation_in_mat).coeffs().transpose();
        std::cout << std::endl;  
    }
    return 0;
}