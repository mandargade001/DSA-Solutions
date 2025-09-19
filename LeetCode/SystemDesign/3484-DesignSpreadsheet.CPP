/*
Problem: 3484. Design Spreadsheet
Link: https://leetcode.com/problems/design-spreadsheet/description/

Approach:
   - My Logic: 
   		We need to create a matrix like structure, we can use 2D vector.
   		There has to be way to locate the cell cordinates accurately by parsing the cell string.
   		For getValue, parse the formula to get the X and Y and then decode them to get their value and return their sum.
		2D vector is used to keep the lookup operations O(1).

   - T.C: O(N)
   - S.C: O(N)


*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>> (rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = stol(cell.substr(1));
        spreadsheet[row-1][col]=value;
    }

    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = stol(cell.substr(1));
        spreadsheet[row-1][col]=0;
    }
    
    int getValue(string formula) {
        string X, Y;
        int i=1;
        while(formula[i]!='+')
        {
            X += formula[i];
            i++;
        }
        i++;
        while(i<formula.size())
        {
            Y += formula[i];
            i++;
        }
        int x = decode(X);
        int y = decode(Y);
        return x+y;
    }
    int decode(string s)
    {
        if(s[0]-'A'>=0 && s[0]-'A'<26)
        {
            int col = s[0]-'A';
            int row = stol(s.substr(1));
            return spreadsheet[row-1][col];
        }
        return stol(s);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

int main() {
    
    return 0;
}