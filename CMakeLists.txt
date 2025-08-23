cmake_minimum_required(VERSION 3.12)
project(SdlChessEngine VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SdlChessEngine main.cpp)

add_subdirectory(Tests/Engine)


enable_testing()

add_executable(EngineTests Tests/Engine/MoveGeneratorTests.cpp)