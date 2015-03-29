PROJECT( faces_detector )
cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
SET(CMAKE_VERBOSE_MAKEFILE ON)
FIND_PACKAGE( OpenCV REQUIRED )
find_package(Boost REQUIRED COMPONENTS filesystem system)

ADD_SUBDIRECTORY(src)
