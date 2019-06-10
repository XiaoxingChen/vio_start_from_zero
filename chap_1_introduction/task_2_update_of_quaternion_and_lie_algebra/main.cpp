#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Matrix3d orientation_in_mat(Eigen::Matrix3d::Identity());
    Eigen::Quaterniond orientation_in_quat(Eigen::Quaterniond::Identity());

    Eigen::Vector3d update;
    update << 0.01, 0.02, 0.03;
    Eigen::Matrix3d update_in_mat = Eigen::AngleAxisd(update.norm(), update).toRotationMatrix();
    Eigen::Quaterniond update_in_quat(Eigen::AngleAxisd(update.norm(), update));

    int it_num = 20;
    for(int i = 0; i < it_num; i++)
    {
        orientation_in_mat = update_in_mat * orientation_in_mat;
        orientation_in_quat = update_in_quat * orientation_in_quat;
        std::cout << "ori in quat: " << orientation_in_quat.coeffs().transpose() << "\t\t";
        std::cout << "ori in mat: " << Eigen::Quaterniond(orientation_in_mat).coeffs().transpose();
        std::cout << std::endl;
        
    }


    return 0;
}