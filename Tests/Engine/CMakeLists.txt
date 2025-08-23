add_executable(EngineTests MoveGeneratorTests.cpp)

target_include_directories(EngineTests PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(EngineTests
    ${SDL2_LIBRARIES}
)