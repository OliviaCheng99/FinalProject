#use a recent version of CMake
cmake_minimum_required (VERSION 3.15)

#the project is called asteroids
project (Xonix)

#the project contains an executable named Xonix that uses the following cpp files
add_executable(Xonix src/main.cpp)

#this says find the graphics, window, and system libraries
#it uses the FindSFML.cmake file to do so and sets
#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

#tells Cmake that the asteroids executable needs to be linked with SFML
target_link_libraries(Xonix sfml-graphics)

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(Xonix PUBLIC -std=c++17)



