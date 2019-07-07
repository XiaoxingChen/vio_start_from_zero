add_executable(testCurveFitting CurveFitting.cpp)
target_link_libraries(testCurveFitting ${PROJECT_NAME}_backend)

add_executable(testQuadraticCurveFitting QuadraticCurveFitting.cpp)
target_link_libraries(testQuadraticCurveFitting ${PROJECT_NAME}_backend)