#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
char PLAYER, COMPUTER;

void resetb() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printb() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkFreespaces() {
    int freespaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playermove() {
    int x, y;
    do {
        printf("Enter a number for rows between (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter a number for columns between (1-3): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ') {
            printf("Invalid move! Try again.\n");
        } else {
            board[x][y] = PLAYER;
            break;
        }
    } while (1);
}

char checkwinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

void printwinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN THIS ROUND!\n");
    } else if (winner == COMPUTER) {
        printf("YOU LOSE THIS ROUND!\n");
    } else {
        printf("IT'S A TIE!\n");
    }
}

void computermove() {
    srand(time(0));
    int x, y;
    if (checkFreespaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
}

void toggleSymbols() {
    char temp = PLAYER;
    PLAYER = COMPUTER;
    COMPUTER = temp;
}

int main() {
    char winner = ' ';
    char response;
    char lastWinner = ' '; // Track who won the last round
    int playerWins = 0; // Track player wins
    int computerWins = 0; // Track computer wins
    int round = 0; // Round counter
    printf("\n");
    printf("LET'S PLAY A GAME OF TIC TAC TOE\n");
    sleep(2);
    printf("\n");

    printf("\n");
    printf("YOU HAVE 7 ROUNDS\n");
    sleep(2);
    printf("\n");
    // Allow the player to choose symbols at the start of the game
    printf("Choose your symbol for this game (X/O): ");
    scanf(" %c", &PLAYER);
    PLAYER = toupper(PLAYER);
    while (PLAYER != 'X' && PLAYER != 'O') {
    printf("Invalid choice! Please choose either 'X' or 'O': ");
    scanf(" %c", &PLAYER);
    PLAYER = toupper(PLAYER); // Convert to uppercase
}



    COMPUTER = (PLAYER == 'X') ? 'O' : 'X'; // Assign opposite symbol to computer

    do {
        round++;
        winner = ' ';
        resetb();

        // Determine who goes first based on the last winner
        if (lastWinner == PLAYER) {
            printf("You go first this round!\n");
        } else if (lastWinner == COMPUTER) {
            printf("Computer goes first this round!\n");
            computermove(); // Computer makes its first move
        }

        while (winner == ' ' && checkFreespaces() != 0) {
            printb();
            if (winner == ' ') {
                playermove();
            }

            winner = checkwinner();
            if (winner != ' ' || checkFreespaces() == 0) {
                break;
            }

            computermove();
            winner = checkwinner();
        }

        printb();
        printwinner(winner);

        // Update the last winner based on the round winner
        lastWinner = winner;
        if (winner == PLAYER) {
            playerWins++; // Increment player's win count
        } else if (winner == COMPUTER) {
            computerWins++; // Increment computer's win count
        }

        // Print current score
        printf("Score after round %d: You - %d, Computer - %d\n", round, playerWins, computerWins);

        // Check if rounds are less than 7
        if (round < 7) {
            printf("Would you like to play the next round? (y/n): ");
            while (getchar() != '\n'); // Clear the input buffer
            scanf(" %c", &response);
            response = toupper(response); // Ensure the response is uppercase

            // Ensure a valid response
            while (response != 'Y' && response != 'N') {
                printf("Invalid response! Please enter 'y' to continue or 'n' to exit: ");
                scanf(" %c", &response);
                response = toupper(response);
            }
        } else {
            // After 7 rounds, display the final winner
            if (playerWins > computerWins) {
                printf("YOU WIN THE GAME!\n");
            } else if (computerWins > playerWins) {
                printf("YOU LOSE THE GAME!\n");
            } else {
                printf("THE GAME IS A TIE!\n");
            }
            break; // Exit after 7 rounds
        }

    } while (response == 'Y'); // Continue if the response is 'Y'

    printf("Thank you for playing!\n");
    return 0;
}





   

