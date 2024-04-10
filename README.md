# Arcade

This repository contains three classic arcade games implemented in JavaScript: Tic Tac Toe, Hangman, and Rock Paper Scissors. These games are designed to be played in a web browser and provide an enjoyable gaming experience for players of all ages.

## Games

### 1. Tic Tac Toe

Tic Tac Toe is a classic two-player game where players take turns placing X's and O's on a 3x3 grid. The objective is to get three of the same symbols in a row (horizontally, vertically, or diagonally) before the other player does.

### 2. Hangman

Hangman is a word-guessing game where one player selects a word, and the other player attempts to guess the word by suggesting letters. For each incorrect guess, a part of the hangman diagram is drawn, and the game ends when the full diagram is completed or the word is correctly guessed.

### 3. Rock Paper Scissors

Rock Paper Scissors is a hand game involving players, forming one of three shapes with their hands: rock, paper, or scissors. The rules are simple: rock beats scissors, scissors beat paper, and paper beats rock.

## Getting Started

To play these games just run Arcade.exe

If it doesn't work open VS Code or similar software and in its terminal run the next commands:

gcc -g -Wall -O3 -c Xand0.c

gcc -g -Wall -O3 -c Hangman.c

gcc -g -Wall -O3 -c RockPaperScissors.c

gcc -g -Wall -O3 -c userMenu.c

gcc -g -Wall -O3 -o Arcade.exe Hangman.o .\Xand0.o .\RockPaperScissors.o .\userMenu.o .\Menu.o

.\Arcade.exe



## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

