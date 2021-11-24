cmake_minimum_required(VERSION 3.20)
project(GKLab)

set(CMAKE_CXX_STANDARD 14)
IF(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    SET(SFML_DIR c:/SFML/lib/cmake/SFML)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
    include_directories(headers /usr/include c:/SFML/include)
ELSE()
    set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
    set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

    if(SFML_FOUND)
        message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
        message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
        message(STATUS "SFML_VERSION: ${SFML_VERSION}")
    endif()
ENDIF()
add_executable(GKLab main.cpp Engine.h Engine.cpp MainMenu.h MainMenu.cpp MenuFun.cpp MenuFun.h Label.h Point2D.h Point2D.cpp Label.cpp Button.h Button.cpp
        KeyListener.h KeyListener.cpp PrimitiveRenderer.h PrimitiveRenderer.cpp KeyListener.cpp MouseListener.h MouseListener.cpp LineSegment.h LineSegment.cpp GameView.h Tank.h Tank.cpp GameFun.h GameFun.cpp Missile.h Missile.cpp AnimatedObject.h AnimatedObject.cpp DrawableObject.h DrawableObject.cpp Pixel.h Obstycle.h Obstycle.cpp GameView.cpp Player.h Player.cpp TransformableObject.h TransformableObject.cpp ShapObject.h LineShape.h LineShape.cpp ShapObject.cpp)
target_link_libraries (GKLab sfml-graphics sfml-window sfml-system)
