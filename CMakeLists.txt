cmake_minimum_required(VERSION 3.12)
project(SdlChessEngine VERSION 0.1.0 LANGUAGES C CXX)

# Поиск необходимых пакетов
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image)

# Добавьте поиск GTest
find_package(GTest REQUIRED)

# Главный исполняемый файл
add_executable(SdlChessEngine 
    main.cpp 
    GUI/GUIComponents/WindowGUIOnly/WindowManager/WindowManager.cpp 
    GUI/GUIComponents/WindowGUIOnly/InputStorage/InputStorage.cpp 
    GUI/GUIComponents/BoardRenderer/Renderer_2D/Renderer_2D.cpp
)

target_include_directories(SdlChessEngine PRIVATE 
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2IMAGE_INCLUDE_DIRS}
)

target_link_libraries(SdlChessEngine 
    ${SDL2_LIBRARIES} 
    ${SDL2IMAGE_LIBRARIES}
)

# Для тестов
enable_testing()

# Тестовый исполняемый файл с всеми необходимыми исходными файлами
add_executable(EngineTests
    Tests/Engine/MoveGeneratorTests.cpp
    Engine/MoveGenerator/MoveGenerator.cpp
    Engine/Board/Board.cpp
    Functions/BitManipulation.h
    # Добавьте другие необходимые файлы реализации
)

target_include_directories(EngineTests PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(EngineTests
    ${SDL2_LIBRARIES}
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME EngineTests COMMAND EngineTests)