cmake_minimum_required(VERSION 3.28)

project(Main CXX)

add_executable(Main Main.cpp)

target_compile_features(Main PRIVATE cxx_std_20)