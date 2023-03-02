#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

void getWelcomeMessage() {
    printf("Rock, Paper and Scissors Game! \n");
    printf("Choose one of the following options \n");
    printf(" (r) for rock \n (p) for paper \n (s) for scissors \n");
}

char getComputerOption() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1:
            return 'r';
            break;
        case 2:
            return 'p';
            break;
        case 3:
            return 's';
            break;
        default:
            return 0;
            break;
    }
}

char getUserOption() {
    char userChoice;
    scanf("%c", &userChoice);
    
    while (userChoice!='r' && userChoice!='p' && userChoice!='s' ) {
        printf("----------------------------------- \n");
        printf("Please enter one of the following options only.");
        printf("\n (r) for rock \n (p) for paper \n (s) for scissors \n");
        scanf("%c", &userChoice);
    }

    return userChoice;
}

void showSelectedOption(char option) {
    switch (option) {
        case 'r':
            printf("Rock \n");
            break;
        case 'p':
            printf("Paper \n");
            break;
        case 's':
            printf("Scissors \n");
            break;
        
        default:
            break;
    }
}

void getWinner(char uChoice, char cChoice) {

    if (uChoice == ROCK && cChoice == PAPER) {
        printf("Computer Wins! Paper wraps Rock. \n");
    } else if (uChoice == PAPER && cChoice == SCISSORS) {
        printf("Computer Wins! Scissors cut Paper. \n");
        
    } else if (uChoice == SCISSORS && cChoice == ROCK) {
        printf("Computer Wins! Rock smashes Scissors. \n");
        
    } else if (uChoice == ROCK && cChoice == SCISSORS) {
        printf("You Win! Paper wraps Rock. \n");
        
    } else if (uChoice == PAPER && cChoice == ROCK) {
        printf("You Win! Paper wraps Rock. \n");
        
    } else if (uChoice == SCISSORS && cChoice == PAPER) {
        printf("You Win! Scissors cut Paper. \n");
    } else {
        printf("Tie. Play again win the Game. \n");
    }
}

void startAnotherGame(char playAgain, char uChoice, char cChoice) {

    printf("Do you want play again? (y/n) \n");

    while(playAgain != 'n') {
        scanf("%c", &playAgain);
        switch (playAgain) {
            case 'y':
                uChoice = getUserOption();
                printf("Your choice is: ");
                showSelectedOption(uChoice);
                
                printf("Computer's choice is: ");

                cChoice = getComputerOption();
                showSelectedOption(cChoice);

                getWinner(uChoice, cChoice);
                printf("Do you want play again? (y/n) \n");

                playAgain='x';
                break;
            case 'n':
                break;
            default:
                break;
        }
    }
}

void startGame(char uChoice, char cChoice) {
    uChoice = getUserOption();
    printf("Your choice is: ");
    showSelectedOption(uChoice);

    cChoice = getComputerOption();
    printf("Computer's choice is: ");
    showSelectedOption(cChoice);

    getWinner(uChoice, cChoice);
}

int main() {
    char uChoice;
    char cChoice;
    char playAgain;
    
    getWelcomeMessage();

    startGame(uChoice, cChoice);
    
    startAnotherGame(playAgain, uChoice, cChoice);

    return 0;
}