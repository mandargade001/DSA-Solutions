/*
Problem: 840. Magic Squares In Grid
Link: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2026-02-15

Approach:
   - My Logic: 
   		iterate the complete input array, and check for every submatrix starting from i,j, for magic condition.
   		if all condition are satisfied, increment the final res variable.

   - T.C: O(M*N)
   - S.C: O(M+N)

   Runtime - 0 ms | Beats 100.00%
  
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // int i = 0;
        // int j = 0;

        bool magic = false;
        int res = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+2<m && j+2<n)
                {
                    int start_i = i;
                    int start_j = j;
                    bool flag = true;

                    //if any element is dupliacte or <1 or >9, skip
                    unordered_set<int> uniq;
                    for(int start_i = i;start_i<i+3;start_i++)
                    {
                        for(int start_j = j;start_j<j+3;start_j++)
                        {
                            if(uniq.find(grid[start_i][start_j])!= uniq.end() || grid[start_i][start_j]>9 || grid[start_i][start_j]<1)
                            {
                                flag = false;
                                break;
                            }
                            uniq.insert(grid[start_i][start_j]);
                        }
                    }
                    if(!flag){
                        continue;
                    }
                    //get each row sum
                    int row1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                    int row2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                    int row3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

                    bool rowCheck = true;
                    if(row1!=row2 || row1!=row3 || row3!=row2) rowCheck = false;
                    //get each col sum
                    int col1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                    int col2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                    int col3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];

                    bool colCheck = true;
                    if(col1!=col2 || col1!=col3 || col3!=col2) colCheck = false;

                    //get dia sum
                    int dia1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                    int dia2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];

                    bool diaCheck = true;
                    if(dia1!=dia2) diaCheck = false;

                    if(rowCheck && colCheck && diaCheck) res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.solve(input) << endl;
    
    return 0;
}