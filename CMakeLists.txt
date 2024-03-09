cmake_minimum_required(VERSION 3.12)
project(cppdotenv VERSION 0.1.0 DESCRIPTION "Environment Variables Loader Library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build tests" OFF)

add_library(${PROJECT_NAME} SHARED
    src/load_env.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(BUILD_TESTS)
    # Download Catch2
    Include(FetchContent)
    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.5.3 # or a later release
    )
    FetchContent_MakeAvailable(Catch2)
    
    add_executable(tests test/test_load_env.cpp)
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain PRIVATE ${PROJECT_NAME})
    target_include_directories(tests PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )
    
    file(COPY ${CMAKE_SOURCE_DIR}/test/test_files DESTINATION ${CMAKE_BINARY_DIR})
endif()



