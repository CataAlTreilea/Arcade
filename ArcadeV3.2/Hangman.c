#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Hangman.h"
#include "userMenu.h"

#define MAX_WORD_LENGTH 100
#define MAX_GUESSES 6

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printHangman(int incorrectGuesses) {
    printf("  +---+\n");
    printf("  |   |\n");
    
    if (incorrectGuesses >= 1) {
        printf("  O   |\n");
    } else {
        printf("      |\n");
    }
    
    if (incorrectGuesses == 2) {
        printf(" /    |\n");
    } else if (incorrectGuesses == 3) {
        printf(" /|   |\n");
    } else if (incorrectGuesses >= 4) {
        printf(" /|\\  |\n");
    } else {
        printf("      |\n");
    }
    
    if (incorrectGuesses == 5) {
        printf(" /    |\n");
    } else if (incorrectGuesses >= 6) {
        printf(" / \\  |\n");
    } else {
        printf("      |\n");
    }
    
    printf("      |\n");
    printf("=========\n");
}

void printWord(const char* word, const int* guessedLetters) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (guessedLetters[i]) {
            printf("%c", word[i]);
        } else if (word[i] == ' ') {
            printf(" ");
        } else {
            printf("_");
        }
        printf(" ");
    }
    printf("\n");
}

int isWordGuessed(const char* word, const int* guessedLetters) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (!guessedLetters[i] && word[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

void Hangman() {
    srand(time(NULL));
    
    char word[MAX_WORD_LENGTH];
    int mode;
    
    printf("\nWelcome to Hangman!\n");
    printf("Select the mode:\n");
    printf("1. Player chooses the word\n");
    printf("2. Random word from dictionary.txt\n");
    printf("3. Exit\n");
    printf("Enter the mode(1-3): ");
    scanf("%d", &mode);
    clearInputBuffer();

    while (mode != 3) {
        if (mode == 1) {
            printf("Enter the word: ");
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = '\0';
        } else if (mode == 2) {
            // Code to read a random word from dictionary.txt

            FILE* dictionary = fopen("dictionary.txt", "r");
            if (dictionary == NULL) {
                printf("Failed to open dictionary.txt\n");
                return ;
            }
            
            int wordCount = 0;
            while (fgets(word, sizeof(word), dictionary) != NULL) {
                wordCount++;
            }
            
            rewind(dictionary);
            int randomIndex = rand() % wordCount;
            for (int i = 0; i <= randomIndex; i++) {
                fgets(word, sizeof(word), dictionary);
            }
            
            fclose(dictionary);
            
            word[strcspn(word, "\n")] = '\0';
        } else {
            printf("Invalid mode\n");
            return;
        }
        
        int wordLength = strlen(word);
        int guessedLetters[MAX_WORD_LENGTH] = {0};
        int incorrectGuesses = 0;
        
        while (1) {
            printf("\n");
            printHangman(incorrectGuesses);
            printWord(word, guessedLetters);
            
            if (isWordGuessed(word, guessedLetters)) {
                printf("Congratulations! You guessed the word!\n\n");
                incrementWinsAndLosses(1, 0);
                break;
            }
            
            if (incorrectGuesses >= MAX_GUESSES) {
                printf("Game over! You ran out of guesses. The hidden word was: %s\n", word);
                incrementWinsAndLosses(0, 1);
                break;
            }
            
printf("Enter a letter: ");
char guess;
char extra;
scanf(" %c%c", &guess, &extra);
clearInputBuffer();

if (!isalpha(guess) || extra != '\n') {
    printf("Invalid input! Please enter a single letter.\n");
    continue;
}
            
            guess = tolower(guess);
            
            int found = 0;
            for (int i = 0; i < wordLength; i++) {
                if (tolower(word[i]) == guess) {
                    guessedLetters[i] = 1;
                    found = 1;
                }
            }
            
            if (!found) {
                printf("Incorrect guess!\n");
                incorrectGuesses++;
            }
        }
        
        printf("\nHangman Game\n");
        printf("1. Player chooses the word\n");
        printf("2. Random word from dictionary.txt\n");
        printf("3. Exit\n");
        printf("Enter the mode: ");
        scanf("%d", &mode);
        clearInputBuffer();
    }

    printf("Exiting the game...\n\n");
    return;


}
