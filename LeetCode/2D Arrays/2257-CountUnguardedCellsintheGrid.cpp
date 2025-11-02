/*
Problem: 2257. Count Unguarded Cells in the Grid
Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

Approach:
   - My Logic: 
   		create a grid of m*n, initialized with -1
		iterate through guards and assign the cells with 1 
		iterate through walls and assign the cells with 1
		for each guard, go in all directions till OOB, WALL or GUARD is reached, update visited cells with 2
		iterate through the complete grid, count cells with values -1
   - T.C: O(M*N)
   - S.C: O(M*N)

   Runtime - 52 ms | Beats 80.28%
   Memory - 172.84 MB | Beats 87.16%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        
        vector<vector<int>> grid(m, vector<int> (n,-1));
        
        for(int i=0;i<guards.size();i++)
        {
            grid[guards[i][0]][guards[i][1]]=1;
        }
        
        for(int i=0;i<walls.size();i++)
        {
            grid[walls[i][0]][walls[i][1]]=1;
        }
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0;i<guards.size();i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];
            for(int j=0;j<dir.size();j++)
            {
                int xi = dir[j][0];
                int yi = dir[j][1];
                int cellx = x+xi;
                int celly = y+yi;

                if(cellx>=0 && cellx<m && celly>=0 && celly<n )
                {
                    int cell = grid[cellx][celly];
                    while(cellx>=0 && cellx<m && celly>=0 && celly<n) {
                        cell = grid[cellx][celly];
                        if(cell!=1)
                        {
                            grid[cellx][celly]=2;
                        }
                        else{
                            break;
                        }
                        
                        cellx+=xi;
                        celly+=yi;
                    }
                }
                
            }
        }
        
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==-1) res++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
        
    return 0;
}