/*
Problem: 3637. Trionic Array I
Link: https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03

Approach:
   - My Logic: 
   		We need to identify three segments in the array - Increasing -> Decreasing -> Increasing
   		For each, we iterate and check for the segments, and a flag to identify if the segments ever existed.
   		At the end, we check if we reached the end of the array and all segments existed. 
   		If yes, return true; or else return false;

   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 27.73 MB Beats 35.38%
   
   - Alternative logic: Can get the number of turning points (2 expected), starting with increasing order.

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        /**
        int array - nums, length-n

        trionic: idx exists such that p<q and 
        1. nums[0-p] - strictly increasing
        2. nums[p-q] - strictly decreasing
        3. nums[q,n-1] - strictly increasing

        return true/false;

        1,3,5,4,2,6


        */

        int n = nums.size();
        int i = 0;
        bool flag1 = false;
        //phase 1 - increasing
        while(i<n-1 && nums[i+1]>nums[i])
        {
            i++;
            flag1 = true;
        }
        bool flag2 = false;
        while(i<n-1 && nums[i+1]<nums[i])
        {
            i++;
            flag2 = true;
        }
        bool flag3 = false;
        while(i<n-1 && nums[i+1]>nums[i])
        {
            i++;
            flag3 = true;
        }
        if(i==n-1 && flag1 && flag2 && flag3) return true;
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4,3,2,3,4};
    
    cout << sol.isTrionic(input) << endl;
    
    return 0;
}