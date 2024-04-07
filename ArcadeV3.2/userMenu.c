#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userMenu.h"

typedef struct {
    char username[50];
    char password[50];
    int wins;
    int losses;
} User;

User loggedInUser;

void registerUser() {
    User newUser;
    User userFromFile;
    FILE *file = fopen("users.csv", "r");

    printf("Enter username: ");
    fgets(newUser.username, sizeof(newUser.username), stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';  // Remove trailing newline character

    // Check if username already exists
    while (fscanf(file, "%[^,],%[^,],%d,%d\n", userFromFile.username, userFromFile.password, &userFromFile.wins, &userFromFile.losses) != EOF) {
        if (strcmp(newUser.username, userFromFile.username) == 0) {
            printf("Username already exists. Try again...\n");
            fclose(file);
            return;
        }
    }

    fclose(file);

    printf("Enter password: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = '\0';  // Remove trailing newline character

    newUser.wins = 0;
    newUser.losses = 0;

    file = fopen("users.csv", "a");
    fprintf(file, "%s,%s,%d,%d\n", newUser.username, newUser.password, newUser.wins, newUser.losses);
    fclose(file);
}

int isLoggedIn = 0;  // Global variable to store the login status

void loginUser() {
    User userFromFile;
    FILE *file = fopen("users.csv", "r");

    printf("Enter username: ");
    fgets(loggedInUser.username, sizeof(loggedInUser.username), stdin);
    loggedInUser.username[strcspn(loggedInUser.username, "\n")] = '\0';  // Remove trailing newline character

    printf("Enter password: ");
    fgets(loggedInUser.password, sizeof(loggedInUser.password), stdin);
    loggedInUser.password[strcspn(loggedInUser.password, "\n")] = '\0';  // Remove trailing newline character

    while (fscanf(file, "%[^,],%[^,],%d,%d\n", userFromFile.username, userFromFile.password, &userFromFile.wins, &userFromFile.losses) != EOF) {
        if (strcmp(loggedInUser.username, userFromFile.username) == 0 && strcmp(loggedInUser.password, userFromFile.password) == 0) {
            fclose(file);
            isLoggedIn = 1;  // Set isLoggedIn to 1 if login is successful
            return;
        }
    }

    fclose(file);
    printf("Invalid username or password. Try again...\n");
}
void displayStats() {
    User userFromFile;
    FILE *file = fopen("users.csv", "r");

    while (fscanf(file, "%[^,],%[^,],%d,%d\n", userFromFile.username, userFromFile.password, &userFromFile.wins, &userFromFile.losses) != EOF) {
        if (strcmp(loggedInUser.username, userFromFile.username) == 0) {
            printf("\nWins: %d\n", userFromFile.wins);
            printf("Losses: %d\n", userFromFile.losses);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("User not found.\n");
}
void incrementWinsAndLosses(int wins, int losses) {
    User users[1000];  // Assume 1000 is the maximum number of users
    User userFromFile;
    int userCount = 0;
    FILE *file = fopen("users.csv", "r");

    // Read the file into a temporary data structure
    while (fscanf(file, "%[^,],%[^,],%d,%d\n", userFromFile.username, userFromFile.password, &userFromFile.wins, &userFromFile.losses) != EOF) {
        users[userCount++] = userFromFile;
    }
    fclose(file);

    // Increment the wins and losses for the logged in user
        for (int i = 0; i < userCount; i++) {
        if (strcmp(loggedInUser.username, users[i].username) == 0) {
            users[i].wins += wins;
            users[i].losses += losses;
            break;
        }
    }

    // Write the updated data back into the file
    file = fopen("users.csv", "w");
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s,%s,%d,%d\n", users[i].username, users[i].password, users[i].wins, users[i].losses);
    }
    fclose(file);
}

void userMenu() {
    char choice[20];

    while (1) {
        printf("\nWelcome to the User Menu!\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice(1-3): ");

        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';  // Remove trailing newline character

        if (strcmp(choice, "1") == 0) {
            registerUser();
        } else if (strcmp(choice, "2") == 0) {
            loginUser();
            if (isLoggedIn == 1) {  // Only continue if the login was successful
                return;
            }
        } else if (strcmp(choice, "3") == 0) {
            return;  // Return if user chooses to exit
        } else {
            printf("Invalid choice. Try again...\n");
        }
    }
}