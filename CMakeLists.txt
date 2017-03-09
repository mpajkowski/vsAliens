cmake_minimum_required(VERSION 3.6)
project(vsAliens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES
        src/main.cpp src/Character.cpp src/Ship.cpp
        src/Bullet.cpp src/Enemy.cpp
        src/Enemy.cpp src/functional.cpp
        src/settings.cpp src/stats.cpp
        src/Bonus.cpp src/Hud.cpp)

add_executable(vsAliens ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(vsAliens ${SFML_LIBRARIES})
endif()