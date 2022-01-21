cmake_minimum_required(VERSION 3.20)
project(GKLab)

set(CMAKE_CXX_STANDARD 14)
IF(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    SET(SFML_DIR c:/SFML1/lib/cmake/SFML)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
    include_directories(headers /usr/include c:/SFML1/include)
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
add_executable(GKLab main.cpp Silnik/Engine.h Silnik/Engine.cpp Projekt/MainMenu.h Projekt/MainMenu.cpp Projekt/MenuFun.cpp Projekt/MenuFun.h Projekt/Label.h Silnik/Point2D.h Silnik/Point2D.cpp Projekt/Label.cpp Projekt/Button.h Projekt/Button.cpp
        Silnik/KeyListener.h Silnik/KeyListener.cpp Silnik/PrimitiveRenderer.h Silnik/PrimitiveRenderer.cpp Silnik/KeyListener.cpp Silnik/MouseListener.h Silnik/MouseListener.cpp Silnik/LineSegment.h Silnik/LineSegment.cpp Projekt/SinglPlayerGame/GameView.h Projekt/Tank.h Projekt/Tank.cpp Projekt/SinglPlayerGame/GameFun.h Projekt/SinglPlayerGame/GameFun.cpp Projekt/Missile.h Projekt/Missile.cpp Silnik/AnimatedObject.h Silnik/AnimatedObject.cpp Silnik/DrawableObject.h Silnik/DrawableObject.cpp Silnik/Pixel.h Projekt/Obstycle.h Projekt/Obstycle.cpp Projekt/SinglPlayerGame/GameView.cpp Projekt/Player.h Projekt/Player.cpp Silnik/TransformableObject.h Silnik/TransformableObject.cpp Silnik/ShapObject.h Silnik/LineShape.h Silnik/LineShape.cpp Silnik/ShapObject.cpp Silnik/BitmapHandler.h Silnik/BitmapHandler.cpp Silnik/BitmapObject.h Silnik/BitmapObject.cpp Silnik/SpriteObject.cpp Silnik/SpriteObject.h Silnik/PlayerObject.h Silnik/PlayerObject.cpp Silnik/DemoFun.h Silnik/DemoFun.cpp Silnik/DemoView.h Projekt/SinglPlayerGame/Pause.h Projekt/EndGame.h Projekt/OnlineGame/OnlineGameView.h Projekt/OnlineGame/OnlineGameView.cpp Projekt/OnlineGame/OnlineGameViewFun.h Projekt/OnlineGame/OnlineGameViewFun.cpp Projekt/OnlineGame/ConectingScreen.h
        Projekt/OnlineGame/ClientServer.h Projekt/OnlineGame/ClientServer.cpp)
target_link_libraries (GKLab  sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
