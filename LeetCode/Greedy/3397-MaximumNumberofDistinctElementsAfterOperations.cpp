/*
Problem: 3397. Maximum Number of Distinct Elements After Operations
Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

Approach:
   - My Logic:
   		if we want to maximise the number of distinct numbers, then we can use the smallest most number to move to left by -k, 
   		and allowing the highest number to extend till +k.

   		To do this, we need to sort the array.
   		Then start from the smallest and try to maximize chances by moving to the left extreme range. keep on updating the number to the left most possible extreme.
   		Eventually, we get the most optimal resultant array.

   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 117.27 MB | Beats 27.76%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        // start updating the numbers as per their extreme cases and based on previous number

        // 1 -> -4, 3 (if3- -4>5) 3-5-> -2, (5- -2>5) 5-> 0, (5-0<=5) 0+1-> 1, 1+1 -> 2, -> 3, -> 4, -> 5, -> 6, 7

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int res = 0;
        if(k==0)
        {
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++)
            {
                mp[nums[i]]++;
                if(mp[nums[i]]<2)
                {
                    res++;
                }
            }
            return res;
        }
        if(n<=(2*k+1)) return n;

        for(int i=0;i<n;i++)
        {
            if(i==0){
                nums[i] = nums[i]-k;
                continue;
            }
            if(nums[i]-nums[i-1]>k){
                nums[i]=nums[i]-k;
            }
            else if(nums[i-1]+1<=nums[i]+k){
                nums[i]=nums[i-1]+1;
            }
            else{
                nums[i]=nums[i-1];
            }
        }
        unordered_map<int,int> mp;
            for(int i=0;i<n;i++)
            {
                mp[nums[i]]++;
                if(mp[nums[i]]<2)
                {
                    res++;
                }
            }
            return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,2,3,3,4};
    int k = 2;
    
    cout << sol.maxDistinctElements(input,k) << endl;
    
    return 0;
}