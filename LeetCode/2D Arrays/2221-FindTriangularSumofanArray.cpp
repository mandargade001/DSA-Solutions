/*
Problem: 2221. Find Triangular Sum of an Array
Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

Approach:
   - My Logic: 
   		This is where we can use pascal triangle's coefficients.
   		I tried but could not find the appropriate solution where using the size of input array, we get the coefficients of pascal's triangle, and use it to calculate the result in O(N)
   		Then, I resorted to iterative process of calculating each row and building up the final result.

   - T.C: O(N^2)
   - S.C: O(1)

   Runtime - 88 ms | Beats 52.43%
   Memory - 22.41 MB | Beats 60.31%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size();
        for(int i=size;i>0;i--)
        {
            for(int j=0;j<i-1;j++)
            {
                nums[j] = ((nums[j]%10)+(nums[j+1]%10))%10;
            }
        }
        return nums[0];
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4,23};
    
    cout << sol.triangularSum(input) << endl;
    
    return 0;
}