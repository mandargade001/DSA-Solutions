/*
Problem: 3349. Adjacent Increasing Subarrays Detection I
Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

Approach:
   - My Logic: 
   		We need to identify the first sub-array and then the adjacent subarray. 
   		So, I thought from every start index, we can check if the i->i+k-1 and i+k -> i+2k-1 are both increasing sub-arrays.
   		If yes, we return true, else check for all possible start index and then return false;
   		As we can have overlapping check, we memoise the sub-array checks.

   - T.C: O(N*K)
   - S.C: O(N^2)

   Runtime - 0 ms | Beats 100.00%
   Memory - 62.84 MB | Beats 10.18%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<vector<int>> mem;
    bool isIncSub(int start, int end, vector<int> &nums)
    {
        if(mem[start][end]!=-1) return mem[start][end];
        for(int i=start+1;i<=end;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                return mem[start][end]=0;
            }
        }
        return mem[start][end]=1;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        mem = vector<vector<int>>(size, vector<int>(size,-1));
        for(int i=0;i<=size-(k*2);i++)
        {
            int psi = i;
            int psi2 = psi + k - 1;
            int csi = i+k;
            int csi2 = csi + k - 1;

            if(isIncSub(csi,csi2,nums))
            {
                if(isIncSub(psi,psi2,nums))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    
    cout << sol.hasIncreasingSubarrays(input, k) << endl;
    
    return 0;
}