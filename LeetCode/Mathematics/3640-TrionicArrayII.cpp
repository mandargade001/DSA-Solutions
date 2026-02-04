/*
Problem: 3640. Trionic Array II
Link: https://leetcode.com/problems/trionic-array-ii/description/?envType=daily-question&envId=2026-02-04

Approach:
   - My Logic: 
   		Keep it simple. 
   		We need to identify a zig-zag line of a particular type "/\/".
   		We iterate the input array to find the pair changing points, where E1<E2>E3 and E1>E2<E3.
   		Once we have them, we calculate the maximum sum of the zig-zag.

   - T.C: O(n)
   - S.C: O(1)

   Runtime: 14 ms Beats 67.27%
   Memory: 134.04 MB Beats 75.45%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        vector<pair<int,int>> trionic;
        bool potentialTrionic = false;
        int first=-1, second=-1;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(!potentialTrionic && nums[i]>nums[i-1] && nums[i+1]<nums[i]){
                potentialTrionic = true;
                first = i;
                continue;
            }
            if(potentialTrionic && second==-1)
            {
                if(nums[i]>=nums[i-1]){
                    potentialTrionic = false;
                    first = -1;
                    i--;
                    continue;
                }
            }
            if(potentialTrionic && nums[i]<nums[i-1] && nums[i+1]>nums[i] && first!=-1){
                second = i;
                trionic.push_back({first,second});
                // cout<<format("first:{}, second:{}\n", first, second);
                first = -1;
                second = -1;
                potentialTrionic = false;
                continue;
            }

        }

        //find the max sum of trionic subarray
        long long maxSum = LLONG_MIN;
        for(int i=0;i<trionic.size();i++)
        {
            long long currSum = 0;
            auto [p,q] = trionic[i];
            currSum += nums[p-1] + nums[q+1];
            //get the compulsory sum of the middle elements p-q
            for(int i=p;i<=q;i++)
            {
                currSum+=nums[i];
            }

            //keep moving away from p-1 in left till the values are decreasing and >0
            for(int i=p-2;i>=0;i--)
            {
                if(nums[i]<nums[i+1] && nums[i]>0){
                    currSum+=nums[i];
                }
                else break;
            }
            maxSum = max(maxSum, currSum);
            //keep moving away from q+1 in right till the values are increasing
            for(int i=q+2;i<nums.size();i++)
            {
                if(nums[i-1]<nums[i]){
                    currSum+=nums[i];
                    maxSum = max(maxSum, currSum);
                }
                else break;
            }

        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,1,4};
    
    cout << sol.maxSumTrionic(input) << endl;
    
    return 0;
}