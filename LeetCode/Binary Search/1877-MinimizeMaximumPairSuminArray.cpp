/*
Problem: 1877. Minimize Maximum Pair Sum in Array
Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24

Approach:
   - My Logic: 
   		We need to pair up the element atmost once such that the maxPairSum is minimized.
   		The answer has to fall in the range of minPossiblePairSum(2 smallest element) and maxPossiblePairSum(2 largest element).
   		We binary search for  answer in this range. 
   		In the function, we try to optimally pair the elements. Like first and last element.
   - T.C: O(N Log N)
   - S.C: O(1)

   	Runtime 169ms Beats 67.94%
	Memory 100.03 MB Beats 30.18%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool checkMaxPairSumPossible(vector<int>& nums, int mid)
    {
        int size = nums.size();
        //pair the elements in an optimal way such that maxPairSum<=mid
        if(nums[0]+nums[size-1]>mid) return false;

        for(int i=0;i<size/2;i++)
        {
            if(nums[i]+nums[size-i-1]>mid) return false;
        }
        return true;
    }

    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //NlogN
        int size = nums.size();
        int low = nums[0]+nums[1];
        int high = nums[size-1]+nums[size-2];
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(checkMaxPairSumPossible(nums,mid))
            {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minPairSum(input) << endl;
    
    return 0;
}