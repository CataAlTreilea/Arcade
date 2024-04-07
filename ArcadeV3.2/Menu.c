#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Xand0.h"
#include "Hangman.h"
#include "RockPaperScissors.h"
#include "userMenu.h"
extern int isLoggedIn;

int main() {
    userMenu();
    if (isLoggedIn == 1) {  // Only display the game menu if the login was successful
        char input[30];
        while (1) {
            printf("\nWelcome to the Game Menu!\n");
            printf("To play a game write 'start [Game Name]'\n");
            printf("To see your stats, type 'stats'\n");
            printf("To exit just type 'Exit'\n");
            printf("1. X and 0\n");
            printf("2. Hangman\n");
            printf("3. RockPaperScissors\n");
            printf("4. Exit\n");
            printf("Visit my Github page at *CataAlTrilulilulea*\n");
            printf("Enter your choice: ");

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character

if (strcmp(input, "start X and 0") == 0) {
            printf("Starting X and 0...\n");
            Xand0();
        } else if (strcmp(input, "start Hangman") == 0) {
            printf("Starting Hangman...\n");
           Hangman();
        } else if (strcmp(input, "start RockPaperScissors") == 0) {
            printf("Starting RockPaperScissors...\n");
            RockPaperScissors();
        } else if (strcmp(input, "Exit") == 0) {
            printf("Exiting...\n");
            break;
         } else if (strcmp(input, "stats") == 0) {
                displayStats();
        } else {
            printf("Invalid input. Please try again.\n");
            continue;
        }
    }

return 0;
}
}