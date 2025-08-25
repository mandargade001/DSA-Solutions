/*
Problem: 118. Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle/description/

Approach:
   - My Logic: 
   		for each row, create a vector of size row_num + 1
   		iterate the row
   			for extremes, set 1
   			else sum of above two elements (tri[row-1][col-1]+tri[row-1][col])
   		Pascal's triangle is ready

   - T.C: O(N*N)
   - S.C: O(N*N)

   - Optimal logic: 
		Space complexity can be reduced to O(N) using the formula - 
		current_element = prev_element * (row_number - col_index) / col_index
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        for(int i=0;i<numRows;i++)
        {
            tri[i]=vector<int>(i+1);
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i) 
                {
                    tri[i][j]=1;
                }
                else
                {
                    tri[i][j]=tri[i-1][j]+tri[i-1][j-1];
                }
                
            }
        }
        return tri;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int numRows = 5;
    
    vector<vector<int>> res = generate(numRows);
    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}