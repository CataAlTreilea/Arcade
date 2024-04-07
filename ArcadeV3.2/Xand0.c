#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Xand0.h"
#include "userMenu.h"

// Function to print the tic-tac-toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to make a move in the game
void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

// Function to check if a move is valid
int isValidMove(char board[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

// Function to play against another player
void playPlayerVsPlayer() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;

    while (1) {
        printBoard(board);

        printf("Player %c's turn\n", currentPlayer);
        printf("Enter row #(1-3): ");
        scanf("%d", &row);
        printf("Enter column #(1-3): ");
        scanf("%d", &col);

        row--;
        col--;

        if (isValidMove(board, row, col)) {
            makeMove(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
            if (currentPlayer == 'X') {
                    incrementWinsAndLosses(1, 0);  // Increment wins for player X
                } else if (currentPlayer == 'O') {
                    incrementWinsAndLosses(0, 1);  // Increment losses for player X
                }
                break;
            }
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to play against AI
void playPlayerVsAI() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;

    srand(time(NULL));  // Seed the random number generator

    while (1) {
        printBoard(board);

        if (currentPlayer == 'X') {
            printf("Player's turn\n");
            printf("Enter row #(1-3): ");
            scanf("%d", &row);
            printf("Enter column #(1-3): ");
            scanf("%d", &col);

            row--;
            col--;
        } else {
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (!isValidMove(board, row, col));
        }

        if (isValidMove(board, row, col)) {
            makeMove(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                if (currentPlayer == 'X') {
                    incrementWinsAndLosses(1, 0);  // Increment wins for player X
                } else if (currentPlayer == 'O') {
                    incrementWinsAndLosses(0, 1);  // Increment losses for player X
                }
                break;
            } else if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

void Xand0() {
    char input[10];
    int choice;

    while (1) {
        printf("\nWelcome to X and 0!\n");
        printf("Select mode:\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs AI\n");
        printf("3. Exit\n");
        printf("Enter your choice(1-3): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1:
                playPlayerVsPlayer();
                break;
            case 2:
                playPlayerVsAI();
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                return ;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


}