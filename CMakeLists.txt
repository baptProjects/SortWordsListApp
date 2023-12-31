cmake_minimum_required(VERSION 3.0)
project(ExerciceLupinSortList)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(ExerciceLupinSortList
    src/LoadAndSave.cpp
    src/ListManipulations.cpp
    src/main.cpp
)

target_compile_options(ExerciceLupinSortList PRIVATE
    -g
    -Wall
)

# Set output directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#add_subdirectory(UnitTests/googletest)

# Include directories for the project and test files
include_directories(${PROJECT_SOURCE_DIR}/include) 
include_directories(${PROJECT_SOURCE_DIR}/test)  # Include the test directory


#target_link_libraries(UnitTests gtest gtest_main)
#target_include_directories(UnitTests PRIVATE ${PROJECT_SOURCE_DIR}/include)