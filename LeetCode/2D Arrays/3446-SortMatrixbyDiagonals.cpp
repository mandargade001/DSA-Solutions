/*
Problem: 3446. Sort Matrix by Diagonals
Link: https://leetcode.com/problems/sort-matrix-by-diagonals/description/

Approach:
   - My Logic: 
   		Divide the grid into two parts, 
   			top-right triangle(above middle diagonal)
   			and, bottom-left triangle(below middle diagonal + middle)
   		Have variable to track the start position for each diagonal
   		for every diagonal, follow the steps - 
   			1. iterate the diagonal & insert values into vector
   			2. sort the vector in desired order
   			3. iteration again to replace diagonal elements in new order

   - T.C: O(N^2 * logN)
   - S.C: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int startR=0, startC=0;
        int size = grid.size();
        if(size==1)
        {
            return grid;
        }
        //iterate the bottom-right + middle diagonal 
        int i=startR, j=startC;
        while(i<size)
        {
            int k=i, l=j;
            vector<int> inplaceS;
            //first iteration, insert into vector
            while(k<size && l<size)
            {
                inplaceS.push_back(grid[k][l]);
                k++;
                l++;
            }
            //sort in descending
            sort(inplaceS.begin(),inplaceS.end(), greater<int>());
            k=i;l=j;
            //iteration again to replace using new order
            for(int z=0;z<inplaceS.size();z++)
            {
                grid[k][j]=inplaceS[z];
                k++;j++;
            }
            i=++startR;
            j=startC;
        }
            
        //iterate the top-right for increasing
        startR=0;
        startC=1;
        i=startR;
        j=startC;
        while(j<size)
        {
            int k=i, l=j;
            vector<int> inplaceS;
            //first iteration, insert into vector
            while(k<size && l<size)
            {
                inplaceS.push_back(grid[k][l]);
                k++;
                l++;
            }
            //sort in descending
            sort(inplaceS.begin(),inplaceS.end());
            k=i;l=j;
            //iteration again to replace using new order
            for(int z=0;z<inplaceS.size();z++)
            {
                grid[k][j]=inplaceS[z];
                k++;j++;
            }
            j=++startC;
            i=startR;
        }
        return grid;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{1,2,3,4},
    	{1,2,3,4},
    	{1,2,3,4},
    	{1,2,3,4}
    };
    
    input = sol.sortMatrix(input);

    for(const auto& row : input) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}