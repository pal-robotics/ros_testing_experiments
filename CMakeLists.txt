cmake_minimum_required(VERSION 2.8.3)
project(ros_testing_experiments)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)
catkin_package(
)

# Tests
if (CATKIN_ENABLE_TESTING)
    include_directories(${catkin_INCLUDE_DIRS})
    find_package(rostest REQUIRED)
    add_rostest_gmock(rostest_cpp test/cpp_rostest.test test/test.cpp)
    target_link_libraries(rostest_cpp
                                ${catkin_LIBRARIES})
    catkin_add_gtest(cpp_test test/test.cpp)
    target_link_libraries(cpp_test
                                ${catkin_LIBRARIES})
    add_rostest(test/py_rostest.test)
    catkin_add_nosetests(test/test.py)

endif(CATKIN_ENABLE_TESTING)
