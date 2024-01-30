#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col);
bool checkForWin(const std::vector<std::vector<char>>& board, char currentPlayer);
bool checkForDraw(const std::vector<std::vector<char>>& board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameInProgress = true;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        initializeBoard(board);

        do {
            displayBoard(board);

            int row, col;

            // Player input
            std::cout << "Player " << currentPlayer << ", enter your move (row and column, separated by space): ";
            std::cin >> row >> col;

            // Make a move
            if (makeMove(board, currentPlayer, row, col)) {
                // Check for a win
                if (checkForWin(board, currentPlayer)) {
                    displayBoard(board);
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }

                // Check for a draw
                if (checkForDraw(board)) {
                    displayBoard(board);
                    std::cout << "It's a draw!\n";
                    break;
                }

                // Switch players for the next turn
                currentPlayer = switchPlayer(currentPlayer);
            } else {
                std::cout << "Invalid move. Try again.\n";
            }

        } while (gameInProgress);

    } while (playAgain());

    return 0;
}

void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "  -----\n";
        }
    }
    std::cout << "\n";
}

bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkForWin(const std::vector<std::vector<char>>& board, char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkForDraw(const std::vector<std::vector<char>>& board) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
