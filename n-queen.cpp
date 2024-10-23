//N-queen problem Code in c++
#include <iostream>
#include <vector>

using namespace std;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();

    // Check the current column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row) {
    int N = board.size();

    // If all queens are placed
    if (row >= N)
        return true;

    // Try placing the queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place queens in the next row
            if (solveNQueens(board, row + 1))
                return true;

            // If placing queen at board[row][col] leads to no solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no place is safe, return false
    return false;
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    // Initialize the chessboard with 0
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        cout << "No solution exists for " << N << " queens." << endl;
    }

    return 0;
}
