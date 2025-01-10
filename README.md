# Tetris

## Project Description

### Overview

Tetris is an action-oriented arcade game where the player must manage falling pieces (representing blocks or "tetriminos") and avoid overfilling the grid. The game simulates falling blocks that the player must rotate and position efficiently within a grid-based system. The gameplay involves swiftly rotating, moving, and clearing rows as the pieces fall. The game is visually displayed using SFML, and implemented entirely in C++, making it a platform-independent application.

### Technologies Used
- **Programming Language**: C++
- **Graphics Library**: SFML (Simple and Fast Multimedia Library)

SFML is used here to handle windowing, rendering images, and processing events such as user inputs, keyboard interactions, and object movements.

### Features & Gameplay
1. **Falling Tetriminos (Blocks)**:
    - The game revolves around managing pieces (called Tetriminos) that fall from the top of the screen to the bottom. The player's goal is to rotate and position these pieces correctly to fill the grid, clearing rows as the game progresses.
    - Each Tetrimino must fall into place on the grid. When it reaches the bottom and isn't placed in a valid position, it can obstruct future Tetriminos and create challenges for the player.

2. **User Input**:
    - **Arrow Keys (Left, Right, Up)**: Used for moving or rotating the falling pieces on the grid.
    - **Down Arrow Key**: Increases the falling speed of the pieces (speeding up the gameplay).
    - **Space Bar**: Triggers a hard drop of the falling pieces directly to their final position.
    - **P Key**: Pauses and unpauses the game, bringing up a pause menu with additional game options.
    - **Other Keys**: Allows for options such as starting a new game, exiting, and displaying game instructions.

3. **Game Logic**:
    - Each Tetrimino is randomly generated at the top of the screen and falls down due to gravity. Players need to rotate and fit the pieces within the grid.
    - A hard drop is available to drop the current piece instantly to its final position.
    - The game runs continuously, with players needing to clear rows of blocks to prevent the grid from filling up entirely. If the Tetriminos reach the top of the screen without fitting into the grid, the game ends.

4. **Background and UI**:
    - The graphical interface is managed by SFML (Simple and Fast Multimedia Library), which handles dynamic rendering of game components such as the playing area, Tetriminos, and pause menu options.
    - The game uses images like tiles, background, frame graphics, and other assets for a visually appealing display.

5. **Game Over**:
    - If Tetriminos reach the top row of the grid without being positioned correctly, the game ends and the player is prompted to start again or exit the game.

6. **Scoring & High Scores**:
    - The score increases with each row that is successfully cleared. Players need to keep clearing rows to reach the highest possible score.

7. **Game Controls**:
    - Simple keyboard controls help manage pieces.
        - Arrow keys: Movement/Rotation
        - Down key: Speed boost
        - Spacebar: Hard fall
        - P: Pause
        - Escape: Exit
        - Num1, Num3, Num4: Help/New game/Exit options from the pause menu

## Functionality

The game has several important functional elements:
- **Piece and Tetrimino Management**:
    - The game simulates the movement of Tetriminos with respect to gravity and interaction with the grid. Logic checks for valid placement within the grid and calculates clearable rows.
  
- **Grid Management**:
    - A grid of cells represents the playing area for placing Tetriminos. The grid ensures that pieces only fit where space is available and rows are cleared once filled completely.
  
- **Game State Management**:
    - The game includes various states, such as the title screen, gameplay screen, pause screen, and game over screen. Transitions between these states are handled using keyboard input.

## Visual Design
- **Graphics**:
    - SFML is used to handle graphics such as background images, grid layouts, Tetriminos, and the boundaries of the game area (the frame).
    - The game dynamically scales and adjusts the layout of Tetriminos, grid spaces, and any other UI elements during gameplay.

- **Animated Tetriminos**:
    - Tetriminos continuously fall within the game window at specified intervals and interact with gravity to land on the grid.

## Game Controls
- The game starts with a simple menu.
- In the gameplay:
    - Arrow keys allow movement of Tetriminos horizontally and vertical rotation.
    - Down key accelerates the fall speed of pieces.
    - Spacebar hard drops pieces immediately.
    - P pauses and resumes the game.
    - Players can access the game menu during the game, where they can choose new games, view instructions, or exit.

## Compilation and Building
1. **Dependencies**:
    - SFML 2.x (or later) is needed for handling graphical rendering and other multimedia tasks.
    - You will need to link the appropriate SFML libraries (`sfml-graphics`, `sfml-window`, `sfml-system`, etc.).

2. **Building Instructions**:
    - **Windows (MinGW)**:
        The game can be compiled using a MinGW-compatible C++ compiler. A suitable Makefile should be used to include all dependencies.
  
    - **Linux**:
        Use `g++` or any compatible compiler with SFML installed, making sure to link the required libraries correctly.
  
    - **MacOS**:
        Similarly, make sure that SFML is installed (can be installed via Homebrew), and link necessary libraries.

## How To Play
1. Launch the game, and you'll be greeted with a start screen.
2. Press `1` to start a new game and use the arrow keys to control the falling Tetriminos.
3. As Tetriminos are dropped, rotate them or adjust their position with the arrow keys to fill gaps in the grid.
4. The game will continue until the grid is filled to the top, or the player successfully clears enough rows.
5. Press `P` to pause the game, view instructions, restart, or exit.

Enjoy Tetris and test your reaction time and problem-solving abilities!

## Ownership and License
This project is created and owned by **Shahmeer Ahmed**.
