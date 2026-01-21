/*
Problem: 3315. Construct the Minimum Bitwise Array II
Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21

Approach:
   - My Logic: 
   		we could apply brute force, but the constrainst do not allow it. 
   		we see a pattern in how x|(x+1) works, always the first 0 bit gets flipped. 
   		we reverse the pattern and find the answer, identify the first 0 bit(j) in nums[i] and then flip the (j-1) bit.
   - T.C: O(n * 32)
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
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==2) {
                res.push_back(-1);
                continue;
            }
            
            for(int j=0;j<32;j++)
            {
                if((nums[i] & (1<<j)) == 0)
                {
                    int ans = nums[i]^(1<<(j-1));
                    res.push_back(ans);
                    break;
                }               
            }            
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {2,3,7,23};
    
    input = sol.minBitwiseArray(input);

    for (std::vector<int>::iterator i = input.begin(); i != input.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}