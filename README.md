# chess
Daimler_task

Description:
This application is a simple chess game.
Architecure is devided on 3 layers:
1. UI (views + controllers) are represented in main.qml
2. Intermaediate layer for binding qml code with game engine ( files with *_qml.cpp)
3. Game engine written in c++;
Game engine was developed using TDD, thats why you will find here also some unittests made with gtest for game-engine.

Note: You can use game engine as a separate module in your application. Once you have notice that the addresses are given in string types
according to chess rules (a1 is the left bottom corner). This means you have to convert from your address type to a1-type, like
it is made in game_qml.cpp.

Bellow you will find the task description:
Once the application starts the screen_1 appears. There should be at least the following elements on the screen: 
Start button – starts a new game. Leads to the screen_2
Load button – allows user to load saved game. Leads to the screen_3
Empty chess board
Screen_2:
Chess pieces are on the board (in initial position). User should be able to move the pieces with mouse according to the standard chess rules. Turn by turn rule must be followed as well (white turn-black turn- white-…). It’s not mandatory to implement the following: castling, check, checkmate. The following buttons should be accessible:
Stop – application stops the game and leads to the screen_1
Save – saves the game history to a file
Screen_3:
Loads a game history and allows to play it step by step using two buttons: “prev” and “next”. The following items are available on the screen:
Start button – starts a new game. Leads to the screen_2
Load button – allows user to load saved game. Leads to the screen_3
Buttons “prev” and “next”
chess board with pieces

P.s.
Each line of code is written from scratch
