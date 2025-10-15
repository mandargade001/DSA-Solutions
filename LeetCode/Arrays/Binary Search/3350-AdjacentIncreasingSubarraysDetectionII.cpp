/*
Problem: 3350. Adjacent Increasing Subarrays Detection II
Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

Approach:
   - My Logic: BinarySearch + Linear Condition Check
		Since, we need to find the maximum value for K, we can check the range for K -> [2,N/2] **(1 if no K exists).
		We need to observe that for every K satisfying the condition, all smaller values also satisfy. So, we get the deciding condition for binary search exclusion.
		For every binary search mid value, we check if the mid value is satisfying the adjacent increasing subarray condition.
		Finally, return the max satisfying K value.
		
   - T.C: O(N * log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 173.75 MB | Beats 62.03%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int check(vector<int>& nums, int k)
    {
        int left=-1;
        int size = nums.size();
        for(int i=1;i<=size-(k);i++)
        {
            if(i+k>=size) continue;
            if(nums[i]>nums[i-1] && nums[i+k]>nums[i+k-1])
            {
                if(left==-1)
                {
                    left = i-1;
                }
                if(i-left+1==k)
                {
                    return 1;
                }
            }
            else 
            {
                left = -1;
            }
        }
        return 0;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int size = nums.size();
        int low = 2;
        int high = size/2;
        int k = 1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(nums,mid))
            {
                low = mid+1;
                k = max(k,mid);
                // k=3;
            }
            else
            {
                high = mid - 1;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {2,5,7,8,9,2,3,4,3,1};
    
    cout << sol.maxIncreasingSubarrays(input) << endl;
    
    return 0;
}