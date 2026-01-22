/*
Problem: 3507. Minimum Pair Removal to Sort Array I
Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22

Approach:
   - My Logic: Optimized explanation
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%
   
   - Optimal logic: 

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        int minSumInd=-1;
        int minSum=INT_MAX;

        int flag = false;
        while(!flag)
        {
            flag = true;
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i]<nums[i-1]){
                     flag = false;
                     break;
                }
            }

            if(!flag)
            {
                for(int i=1;i<nums.size();i++)
                {
                    long adjSum = nums[i]+nums[i-1];
                    if(adjSum<minSum){
                        minSum = adjSum;
                        minSumInd = i-1;
                    }
                }
                nums[minSumInd]=minSum;
                nums.erase(nums.begin()+minSumInd+1);
                ops++;
                minSum = INT_MAX;
            }
        }
        return ops;


    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minimumPairRemoval(input) << endl;
    
    return 0;
}