cmake_minimum_required(VERSION 3.14)
project(LP25 C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(LP25 main.c draw/draw.h draw/drawResetButton.c draw/drawChessboard.c draw/drawSprite.c eventDetector.h eventDetector.c positionOnChessBoard.c checkDamePosition.c board/boxStructure.h board/initBoard.c board/board.h)
target_link_libraries(LP25 ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)