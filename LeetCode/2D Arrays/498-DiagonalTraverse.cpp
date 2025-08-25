/*
Problem: 498. Diagonal Traverse
Link: https://leetcode.com/problems/diagonal-traverse/

Approach:
   - My Logic: 
   		Identify the start points for each iteration, which are the 1st column & Last row.
   		Starting from them, iterate diagonally (p--, q++) till you go out of bound.
   		Keep an eye on starting from correct coordinates.

   - T.C: O(N*N)
   - S.C: O(1)

   - Optimal logic: 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> res;
        int p,q;

        for(int i=0;i<m;i++)
        {
        	p=i;q=0;
        	while(p>=0 && q<n)
        	{
        		res.push_back(mat[p][q]);
        		p--;q++;
        	}
        }
        for(int j=1;j<n;j++)
        {
        	p=m-1;q=j;
        	while(p>=0 && q<n)
        	{
        		res.push_back(mat[p][q]);
        		p--;q++;
        	}
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
    
    vector<int> res = sol.findDiagonalOrder(input);

    for(int num: res)
    {
    	cout<<num<<" ";
    }
    
    return 0;
}