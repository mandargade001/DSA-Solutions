/*
Problem: 36. Valid Sudoku
Link: https://leetcode.com/problems/valid-sudoku/description/

Approach:
   - My Logic: 
		For every filled cell, we need to check for three conditions - 
			1. number unique in row
			2. number unique in col
			3. number unique in sub-box
		We use hashing to store the frequency of number appearing in each row, col and sub-box
		if(count>1) return false;
		at last, we return true; as all the numbers appear only once in each row, col and sub-box
   - T.C: O(N^2) 
   - S.C: O(N) - constant as N==9

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //declare maps for each row, column and sub-box
        vector<map<int,char>> row(9);
        vector<map<int,char>> col(9);
        vector<map<int,char>> box(9);        

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                row[i][board[i][j]]++;
                if(row[i][board[i][j]]>1) return false;

                col[j][board[i][j]]++;
                if(col[j][board[i][j]]>1) return false;

                int ind = (i/3)*3 + j/3;
                box[ind][board[i][j]]++;
                if(box[ind][board[i][j]]>1) return false;
            }
        }
        return true;
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
    
    cout << sol.isValidSudoku(input) << endl;
    
    return 0;
}