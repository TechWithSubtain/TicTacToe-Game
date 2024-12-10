#include <iostream>
using namespace std;

// Global grid array for the Tic Tac Toe board
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function prototypes
int checkwin();
void board();

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        board(); // Display the board
        player = (player % 2) ? 1 : 2; // Alternate players
        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O'; // Assign 'X' or 'O' based on player

        // Mark the board based on the player's choice
        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
        } else {
            cout << "Invalid move. Try again!\n";
            player--; // Revert player turn for invalid input
        }

        i = checkwin(); // Check the game status
        player++;
    } while (i == -1);

    board(); // Final board display

    if (i == 1)
        cout << "==> Player " << --player << " wins! 🎉\n";
    else
        cout << "==> Game Draw! 🤝\n";

    return 0;
}

// Function to check the game status: Win, Draw, or Continue
int checkwin() {
    // Winning combinations
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;

    // Check for draw
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    // Continue game
    else
        return -1;
}

// Function to display the Tic Tac Toe board
void board() {
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  \n";
    cout << "     |     |     \n\n";
}
// Project End