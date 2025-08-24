/*
Problem: 54 - Spiral Matrix
Leetcode link: https://leetcode.com/problems/spiral-matrix/

Approach:
   - Logic: 
   		Have variables for top=0, bottom=m-1, right=n-1, and left=0 indicating their extreme values.
   		There are move loops - 
   			1. horizontal right movement
   			2. vertical down movement
   			3. horizontal left movement
   			4. vertical up movement
   		Update the iterating row/col after each loop. 
   		Repeat till the m*n elements are traversed.

   - T.C: O(M*N)
   - S.C: O(N) - Result array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>res;
        
        int t=0;int r=n-1;int b=m-1;int l=0;
        while(res.size()<m*n)
        {
            //case 1: horizontal Right
            for(int j=l;j<=r;j++)
            {
                res.push_back(matrix[t][j]);
            }
            t++;
            if(res.size()==m*n)break;
            //case 2: vertical down
            for(int i=t;i<=b;i++)
            {
                res.push_back(matrix[i][r]);
            }
            r--;
            if(res.size()==m*n)break;
            //case 3: horizontal Left
            for(int j=r;j>=l;j--)
            {
                res.push_back(matrix[b][j]);
            }
            b--;
            if(res.size()==m*n)break;
            //case 4: vertical up
            for(int i=b;i>=t;i--)
            {
                res.push_back(matrix[i][l]);
            }
            l++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{1,2,3},
    	{4,5,6},
    	{7,8,9}
    };
    
    vector<int> res = sol.spiralOrder(input);

    for (int num : res) {
        cout << num << " ";
    }    
    return 0;
}