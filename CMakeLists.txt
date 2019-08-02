cmake_minimum_required(VERSION 2.8)
project(dbfs_algo)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_library(worldmodel_dbfs SHARED include/grid_define.h
                        include/worldmodel.h src/worldmodel.cpp
                        src/searchingalgorithm.cpp
                        )

add_executable(DBFS_test src/main.cpp  )
target_link_libraries(DBFS_test worldmodel_dbfs ${PYTHON_LIBRARIES})

