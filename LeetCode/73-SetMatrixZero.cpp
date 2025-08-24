/*
Problem: 73 - Set Matrix Zeroes

Approach:
   - Logic: 
       Have two vectors for rowV(m) + colV(n). Update index in rowV/colV with 1 if matrix element is 0. 
       Then reiterate and check value in rowV & colV and update value to 0.
   - T.C: O(M*N)
   - S.C: O(M+N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> rowV(m,0);
        vector<int> colV(n,0);

        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(matrix[i][j]==0)
        		{
        			rowV[i]=1;
        			colV[j]=1;
        		}
        	}
        }
        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(rowV[i]==1 || colV[j]==1)
        		{
        			matrix[i][j]=0;
        		}
        		cout<<matrix[i][j]<<" ";
        	}
        	cout<<endl;
        }
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{0,1,2,0},
    	{3,4,5,2},
    	{1,3,1,5}
    };
    
    sol.setZeroes(input);
    
    return 0;
}