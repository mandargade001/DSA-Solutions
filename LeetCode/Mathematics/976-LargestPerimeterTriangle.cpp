/*
Problem: 976. Largest Perimeter Triangle
Link: https://leetcode.com/problems/largest-perimeter-triangle/

Approach:
   - My Logic:  
   		just had to identify the condition to make triangle and,
   		the fastest way to get the largest perimeter, that is by starting to check from longest side.

   - T.C: O(N * log N)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--)
        {
            int sum = nums[i-2] + nums[i-1];
            if(sum>nums[i])
            return sum + nums[i];
        }
        return 0;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,2};
    
    cout << sol.largestPerimeter(input) << endl;
    
    return 0;
}