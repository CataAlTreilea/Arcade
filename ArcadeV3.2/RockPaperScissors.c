#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RockPaperScissors.h"
#include "userMenu.h"


void playGame() {
	int playerChoice, computerChoice;
	//const char* choices[] = {"Rock", "Paper", "Scissors"};
	const char* symbols[] = {  
		"   _______\n"
		"---'   ____)\n"
		"      (_____)\n"
		"      (_____)\n"
		"      (____)\n"
		"---.__(___)\n",
		
		"   _______\n"
		"---'   ____)____\n"
		"          ______)\n"
		"          _______)\n"
		"         _______)\n"
		"---.__________)\n",
		
		"   _______\n"
		"---'   ____)____\n"
		"          ______)\n"
		"       __________)\n"
		"      (____)\n"
		"---.__(___)\n"
	};

	
	printf("\nChoose your move:\n");
	printf("1. Rock\n");
	printf("2. Paper\n");
	printf("3. Scissors\n");
	printf("Enter your choice (1-3): ");
	scanf("%d", &playerChoice);

	if (playerChoice < 1 || playerChoice > 3) {
		printf("Invalid choice. Please try again.\n");
		return;
	}

	playerChoice--;  // Adjust to array index

	srand(time(NULL));
	computerChoice = rand() % 3;

	printf("Player choice:\n%s\n", symbols[playerChoice]);
	printf("Computer choice:\n%s\n", symbols[computerChoice]);

	if (playerChoice == computerChoice) {
		printf("It's a tie!\n");
	} else if ((playerChoice == 0 && computerChoice == 2) ||
			   (playerChoice == 1 && computerChoice == 0) ||
			   (playerChoice == 2 && computerChoice == 1)) {
		;
		printf("Player wins!\n");
		incrementWinsAndLosses(1, 0);
	} else {
		
		printf("Computer wins!\n");
		incrementWinsAndLosses(0, 1);
	}
}

void RockPaperScissors() {
    char input[10];
    int choice;

    while (1) {
        printf("\nWelcome to Rock Paper Scissors!\n");
        printf("Select mode:\n");
        printf("1. Play the game\n");
        printf("2. Exit\n");
        printf("Enter your choice (1-2): ");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 1) {
            playGame();
        } else if (choice == 2) {
            printf("Exiting...\n");
            return;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}