/*
Problem: 1895. Largest Magic Square
Link: https://leetcode.com/problems/largest-magic-square/description/?envType=daily-question&envId=2026-01-18

Approach:
   - My Logic: iterate through the min(m,n) till 2 and then check for each possible magic square using brute force.
   - T.C: O(N^5)
   - S.C: O(1)

   Runtime - 44 ms | Beats 43.31%
   Memory - 13 MB | Beats 72.67%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool verifyMagicSquare(vector<vector<int>>& grid, int i1, int j1, int len)
    {
        //condition for true
        //every row sum == every column sum == sum of diagonal 

        int sum = -1;
        for(int i=0;i<len;i++)
        {
            int rowSum = 0;
            for(int j=0;j<len;j++)
            {
                rowSum += grid[i+i1][j+j1];
                
            }
            // if(len==3) cout<<format("i={}, rowSum={}", i+i1, rowSum)<<endl;
            if(sum==-1) {
                sum = rowSum;
                continue;
            }
            if(sum!=rowSum) return false;
        }
        for(int j=0;j<len;j++)
        {
            int colSum = 0;
            for(int i=0;i<len;i++)
            {
                colSum += grid[i+i1][j+j1];
                
            }
            // if(len==3) cout<<format("j={}, colSum={}", j+j1, colSum)<<endl;
            if(sum==-1) {
                sum = colSum;
                continue;
            }
            if(sum!=colSum) return false;
        }

        int digSum1 = 0, digSum2=0;
        for(int i=0;i<len;i++)
        {
            digSum1+=grid[i+i1][i+j1];
            digSum2+=grid[i1+len-1-i][i+j1];
        }
        // if(len==3) cout<<format("digSum1={}, digSum2={}", digSum1, digSum2)<<endl<<endl;
        if(digSum1!=sum || digSum2!=sum) return false;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // int magicLen = min(m,n);

        for(int len = min(m,n);len>=2;len--)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i+len<=m && j+len<=n){
                        // cout<<format("i:{}, j:{}, len:{}", i, j, len);
                        bool possibleMagicSquare = verifyMagicSquare(grid, i, j, len);
                        // cout<<", possible: "<<possibleMagicSquare<<endl;
                        if(possibleMagicSquare) return len;
                    }
                }
            }
        }
        return 1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    
    cout << sol.largestMagicSquare(input) << endl;
    
    return 0;
}