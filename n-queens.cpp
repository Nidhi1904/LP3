#include <bits/stdc++.h>
using namespace std;

// Check if placing a queen at position (row, col) is safe
bool isSafe(int row, int col, vector<string> board, int n) {
    int dupRow = row;
    int dupCol = col;

    // Check upper-left diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    // Check same column above current position
    col = dupCol;
    row = dupRow;
    while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // Check lower-left diagonal
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

// Recursive function for finding all valid arrangements of N-Queens
void f(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col == n) {
        ans.push_back(board); // Found a valid arrangement, add to the answer
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q'; // Place queen if safe
            f(col + 1, board, ans, n); // Recur for next column
            board[row][col] = '.'; // Backtrack: Reset the position
        }
    }
}

// Function to solve N-Queens problem
vector<vector<string>> solve(int n, int pos) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.')); // Initialize board with empty '.' strings
    board[pos][0] = 'Q'; // Place the first queen at specified position in the first column
    f(1, board, ans, n); // Start finding solutions for the remaining queens
    return ans; // Return all valid arrangements
}

int main() {
    int n;
    cin >> n; // Input size of the chessboard
    int pos;
    cin >> pos; // Input initial position of the queen in the first column
    vector<vector<string>> ans = solve(n, pos); // Find solutions
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j]; // Print each arrangement
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
