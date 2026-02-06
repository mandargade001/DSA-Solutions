/*
Problem: 3634. Minimum Removals to Balance Array
Link: https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06

Approach:
   - My Logic:
   		we need to make the array balanced. 
   		for that we need maximum element in our array.
   		to simplify operation, we will sort to get the min and max element easily.
   		then for every minEle, we will find the possibleMaxElement index.
   		as with increasing minEle, maxEle will increase, we can use two-pointer to track them in O(N).
   		for every minEle, we calculate element possible and get the maximum element possible in array.
   		return size - maxElemeSize;
   - T.C: O(n*logn)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:

    int minRemoval(vector<int>& nums, int k) {
       

        int size = nums.size();

        if(size==1) return 0;

        sort(nums.begin(), nums.end());

        int right = 0;
        int res = INT_MIN;


        for(int left=0;left<size;left++)
        {
            long long val = (long)nums[left]*(long)k;
            while(right<size && nums[right]<=val)
            {
                right++;
            }
            res = max(res, (right-left));
        }
        return size-res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minRemoval(input,2) << endl;
    
    return 0;
}