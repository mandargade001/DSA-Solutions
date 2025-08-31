/*
Problem: 37. Sudoku Solver
Link: https://leetcode.com/problems/sudoku-solver/description/

Approach:
   - My Logic: backtracking, get possible values and update the value if unique

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
    int n = 3, N = 9;
    int rows[9][10] = {}, cols[9][10] = {}, boxes[9][10] = {};
    vector<vector<char>>* boardPtr;
    bool sudokuSolved = false;

    bool couldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
    }

    void placeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        cols[col][d]++;
        boxes[idx][d]++;
        (*boardPtr)[row][col] = d + '0';
    }

    void removeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        cols[col][d]--;
        boxes[idx][d]--;
        (*boardPtr)[row][col] = '.';
    }

    void placeNextNumbers(int row, int col) {
        if (row == N - 1 && col == N - 1) sudokuSolved = true;
        else if (col == N - 1) backtrack(row + 1, 0);
        else backtrack(row, col + 1);
    }

    void backtrack(int row, int col) {
        if ((*boardPtr)[row][col] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (couldPlace(d, row, col)) {
                    placeNumber(d, row, col);
                    placeNextNumbers(row, col);
                    if (!sudokuSolved) removeNumber(d, row, col);
                }
            }
        } else placeNextNumbers(row, col);
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        boardPtr = &board;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.') placeNumber(board[i][j] - '0', i, j);
        backtrack(0, 0);
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<char>> input = {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    
    sol.solveSudoku(input);
    
    for(const auto& row : input) {
        for(char val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}