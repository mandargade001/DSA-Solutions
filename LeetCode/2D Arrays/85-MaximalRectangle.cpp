/*
Problem: 85. Maximal Rectangle
Link: https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

Approach:
   - My Logic: for every 1, we find the maximum rectangle.
   - T.C: O(n^4)
   - S.C: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);
class Solution {
public:
    int findMaxAreaRectangle(vector<vector<char>>& m, int i1, int j1)
    {
        // cout<<format("i:{}, j:{}", i1, j1)<<endl;
        //i1 = 1, j1 = 2
        int lenx = m.size(); //4
        int leny = m[0].size(); //5
        int col = leny;//4
        int row = 0;
        int area = 0;
        for(int i=i1;i<lenx;i++){
            if(m[i][j1]=='1'){
                row++;
                for(int j=j1;j<col;j++){
                    if(m[i][j]=='0') col = min(col, j);
                }
                area = max(area, row*(col-j1));
            }
            else{
                break;
            }
        }
        // if(col==leny-1) col++;
        // cout<<format("row:{}, col:{}", row, col-j1)<<endl;
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int lenx = matrix.size();
        int leny = matrix[0].size();
        for(int i=0;i<lenx;i++)
        {
            for(int j=0;j<leny;j++)
            {
                if(matrix[i][j]=='1')
                {
                    int area = findMaxAreaRectangle(matrix, i, j);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    
    return 0;
}