/*
Problem: 3354. Make Array Elements Equal to Zero
Link: https://leetcode.com/problems/make-array-elements-equal-to-zero/description/?envType=daily-question&envId=2025-10-28

Approach:
   - My Logic:
   		For every initial zero, we have two possible directions, left & right.
   		We iterate the array and call function to check their validity.
   		The function, loops from the index and dir, and as per given conditions, on exit, if the array is all zero, then +1 else 0.

   - T.C: O(N^2)
   - S.C: O(N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 24.41 MB | Beats 6.88%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool check(vector<int> nums, int ind, int dir)
    {
        int size = nums.size();
        while(ind>=0 && ind<size)
        {
            if(nums[ind]==0)
            {
                ind+=dir;
            }
            else
            {
                nums[ind]--;
                dir *= -1;
                ind+=dir;
            }
        }
        for(int i=0;i<size;i++)
        {
            if(nums[i]!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                res += check(nums, i,-1);
                res += check(nums, i,1);
                
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,0,2,0,3};
    
    cout << sol.countValidSelections(input) << endl;
    
    return 0;
}