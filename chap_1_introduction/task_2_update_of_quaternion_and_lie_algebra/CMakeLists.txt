cmake_minimum_required(VERSION 2.8)
project(update_compare)

find_package(Eigen3)
find_package( Sophus REQUIRED )

include_directories(
    ${EIGEN3_INCLUDE_DIRS}
    ${Sophus_INCLUDE_DIRS})

add_compile_options(-std=c++11)

add_executable(update_compare main.cpp )
target_link_libraries(update_compare ${Sophus_LIBRARIES})
    
