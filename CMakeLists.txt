cmake_minimum_required(VERSION 3.12)
project(cppdotenv VERSION 1.0 DESCRIPTION "Environment Variables Loader Library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cppdotenv SHARED
    src/loadEnv.cpp
)

target_include_directories(cppdotenv PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

