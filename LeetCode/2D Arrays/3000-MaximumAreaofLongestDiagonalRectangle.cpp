/*
Problem: 3000. Maximum Area of Longest Diagonal Rectangle
Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/

Approach:
   - My Logic: 
   		Iterate each row, calculate diagonal(sqrt(a^2+b^2)) and area(a*b).
   		update diagonal and area if(curr>longest)
   		if(curr==longest) -> check for max area and update accordingly.
   - T.C: O(N)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longD=0, maxA=0;
        int m=dimensions.size();
        for(int i=0;i<m;i++)
        {
            int a=dimensions[i][0];
            int b=dimensions[i][1];
            int dia = a*a + b*b;
            if(dia>longD)
            {
                longD=dia;
                maxA=a*b;
            }
            else if(dia==longD && a*b > maxA) maxA=a*b;
        }
        return maxA;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{9,3},
    	{8,6}
    };
    
    cout << sol.areaOfMaxDiagonal(input) << endl;
    
    return 0;
}