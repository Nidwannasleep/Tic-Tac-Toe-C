
#include <stdio.h>

char board[3][3];


void initBoard() {
    int i, j;
    char num = '1';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = num;
            num++;
        }
    }
}


void displayBoard() {
    int i, j;

    printf("\n TIC TAC TOE GAME\n\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);

            if (j < 2) {
                printf("|");
            }
        }

        printf("\n");

        if (i < 2) {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}


int checkWin(char p) {
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] == p &&
            board[i][1] == p &&
            board[i][2] == p)
            return 1;

        if (board[0][i] == p &&
            board[1][i] == p &&
            board[2][i] == p)
            return 1;
    }

    if (board[0][0] == p &&
        board[1][1] == p &&
        board[2][2] == p)
        return 1;

    if (board[0][2] == p &&
        board[1][1] == p &&
        board[2][0] == p)
        return 1;

    return 0;
}

int main() {
    int choice, row, col;
    int turn, valid;
    char player;
    char again;

    do {
        initBoard();
        turn = 0;

        while (turn < 9) {
            displayBoard();

            if (turn % 2 == 0)
                player = 'X';
            else
                player = 'O';

            printf("Player %c, choose (1-9): ",
                   player);

            valid = scanf("%d", &choice);

            if (valid != 1) {
                int c;
                while ((c = getchar()) != '\n'
                       && c != EOF);
                printf("Invalid input!\n");
                continue;
            }

            if (choice < 1 || choice > 9) {
                printf("Choose from 1 to 9!\n");
                continue;
            }

            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                printf("This cell is taken!\n");
                continue;
            }

            board[row][col] = player;
            turn++;

            if (checkWin(player)) {
                displayBoard();
                printf("Player %c wins!\n", player);
                break;
            }
        }

        if (turn == 9 && !checkWin(player)) {
            displayBoard();
            printf("It's a draw!\n");
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}
