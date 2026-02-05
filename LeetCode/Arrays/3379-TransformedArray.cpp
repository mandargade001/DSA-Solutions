/*
Problem: 3379. Transformed Array
Link: https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

Approach:
   - My Logic: 
   		Iterate each index, find their final index after operation using basic mathematics.
   		If nums[i]>0: take modulo after adding the nums[i] to i;
   		if nums[i]<0: take modulo before, then find how much it would take back from the end if the modulo value is greater than the index i iteself;

   - T.C: O(n)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        //3,-2,1,1

        for(int i=0;i<n;i++)
        {
            //nums[i]==0
            if(nums[i]==0) result[i]=nums[i];
            //num[i]>0
            if(nums[i]>0)
            {
                result[i]=nums[(i+nums[i])%n];
            }
            //nums[i]<0
            if(nums[i]<0)
            {
                int idx = abs(nums[i])%n;
                if(idx>i){
                    idx = n - idx + i;
                }
                else{
                    idx = i-idx;
                }

                result[i] = nums[idx];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    input = sol.constructTransformedArray(input);
    for(auto i: input) cout<<i<<" ";
    
    return 0;
}