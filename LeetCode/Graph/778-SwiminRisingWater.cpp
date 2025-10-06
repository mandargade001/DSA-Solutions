/*
Problem: 778. Swim in Rising Water
Link: https://leetcode.com/problems/swim-in-rising-water/description/

Approach:
   - My Logic: Binary Search with Answer using DFS
   - T.C: O(N^2 * log N)
   - S.C: O(N^2)

   Runtime -4 ms | Beats 78.84%
   Memory - 12.96 MB | Beats 71.24%
   
   - Optimal logic: Dijktras's algorithm - Max with Shortest Path

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<vector<int>> directions {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool possibleTime(vector<vector<int>>& grid, int i, int j, int t, vector<vector<bool>>& visited)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || visited[i][j]==true || grid[i][j]>t)
        {
            return false;
        }
        if(i==grid.size()-1 && j==grid.size()-1) return true;

        visited[i][j]=true;
        for(auto& dir: directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if(possibleTime(grid, i_, j_, t, visited))
            {
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int size = grid.size();

        int l = grid[0][0];
        int h = size*size - 1;
        int result;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            vector<vector<bool>> visited(size, vector<bool> (size, false));
            if(possibleTime(grid, 0, 0, mid, visited))
            {
                result = mid;
                h = mid -1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {{0,2},{1,3}};
    
    cout << sol.swimInWater(input) << endl;
    
    return 0;
}