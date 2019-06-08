cmake_minimum_required(VERSION 3.14)
project(DamAss C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(DamAss main.c draw/draw.h draw/drawResetButton.c draw/drawChessboard.c board/setCellSprite.c event/eventDetector.h event/eventDetector.c board/checkDameConflict.c board/cellStructure.h board/initBoard.c board/board.h board/getPositionOnBoard.c draw/drawHelp.c draw/drawSquareHelp.c draw/initGameWindows.c draw/drawScoreBoard.c board/setConflictLine.c board/setPreventSquareHelp.c board/resolver.c draw/initHome.c event/eventHomeDetector.c draw/setTextNbDame.c draw/clearSelectedLevel.c draw/drawMenuButton.c draw/drawEndMessage.c draw/drawCheckButton.c board/resetConflicts.c event/eventEndDetector.c)
target_link_libraries(DamAss ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -mwindows)
