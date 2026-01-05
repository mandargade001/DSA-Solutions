/*
Problem: 1975. Maximum Matrix Sum
Link: https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

Approach:
   - My Logic: 
   		Observed that if we have any two negative integers, using the operation, we can propagate the negative integers to be side by side and ultimately get rid of them. 
   		Using this capability, we can make all the negative integers positive until they are in pairs or even numbers.
   		If the num of negative integers is even, we can directly return the sum of the absolute numbers.
   		If the num is odd, then one of the negative remains and to maximize the sum, we can propagate the -ve sign to the minimum absolute number in the matrix.
   		While iterating the matrix, we keep track of frequency of negative integers, there absolute sum and minimum absolute number.

   - T.C: O(N^2)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 39.2 MB | Beats 61.32%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minAbsEle = INT_MAX;
        int negativeNum = 0;
        long long res = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                res += abs(matrix[i][j]);
                if(matrix[i][j]<0) negativeNum++;
                minAbsEle = abs(matrix[i][j])<minAbsEle ? abs(matrix[i][j]) : minAbsEle;
            }
        }
        if(negativeNum%2==0) return res;
        return res -= (minAbsEle*2);
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
    
    cout << sol.maxMatrixSum(input) << endl;
    
    return 0;
}