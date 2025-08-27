/*
Problem: 3459. Length of Longest V-Shaped Diagonal Segment
Link: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/

Approach:
   - My Logic: recursive dfs
   		For every element=1, there are four directions in which we can start looking.
   		For each direction, there are two options - 
   			1. go in straight diagonal
   			2. turn if available
		Keep track of maximum segment for both options across all 1's present in grid.

   		**create grid, n, m, directions global so that we don't need to pass again and again in the recursive function.
		
   - T.C: O(N^M)
   - S.C: O(1) 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{-1,1},{1,1},{1,-1},{-1,-1}};
    int n;
    int m;
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    res = max(res,1);
                    //traverse in the four diagonal directions from the starting point
                    res = max(res,dfs(i,j,0,2,false));
                    res = max(res,dfs(i,j,1,2,false));
                    res = max(res,dfs(i,j,2,2,false));
                    res = max(res,dfs(i,j,3,2,false));
                }
            }
        }
        return res;
    }

    int dfs(int i,int j,int dir,int target,int turned){
        int x = i+directions[dir][0];
        int y = j+directions[dir][1];

        //stopping condition
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=target){
            return 1;
        }
        //iterate options
        //1. go in straight diagonal
        int straight = 1 + dfs(x,y,dir,target==2?0:2,turned);

        //2. turn if available
        int turn = 1;
        if(!turned){
            turn = 1 + dfs(x,y,(dir+1)%4,target==2?0:2,true);
        }

        //return final max value
        return max(straight,turn);
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{2,2,1,2,2},
    	{2,0,2,2,0},
    	{2,0,1,1,0},
    	{1,0,2,2,2},
    	{2,0,0,2,2}
    };
    
    cout << sol.lenOfVDiagonal(input) << endl;
    
    return 0;
}