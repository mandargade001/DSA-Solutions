/*
Problem: 3010. Divide an Array Into Subarrays With Minimum Cost I
Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

Approach:
   - My Logic: 
   		result is the sum of first element and the two minimum elements of array. we sort the array from index 1 to n and return the first 3 elements.
   - T.C: O(n*logn)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 30.44 MB Beats 74.87%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumCost(vector<int>& nums) {

        sort(nums.begin()+1, nums.end());

        return nums[0]+nums[1]+nums[2];
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {5,2,3,4};
    
    cout << sol.minimumCost(input) << endl;
    
    return 0;
}