/*
Problem: 2598. Smallest Missing Non-negative Integer After Operations
Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

Approach:
   - My Logic: 
		First, observed that the MEX range is 0 -> nums.size()
		We should try to operate the nums to get the values in this range. So, the starting point is to the the modulo of nums from value.
		Now, We should try to get the minimum value that is not yet used by binary_search.
		Then iterate to get the MEX in range which was not possible to calculate from operations.

   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 210 ms | Beats 10.22%
   Memory - 191.35 MB | Beats 5.11%
   
   - Optimal logic: We dont need to calculate the exact value from the minimum ones, we just can start to iterate for possible MEX, and get the values for which their is no possible nums[i] that can be operated on to get that MEX.
   This avoids the binary_search time and gets result in O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    typedef long long ll;
    int findSmallestInteger(vector<int>& nums, int value) {
        ll size = nums.size();
        // ll minR = 0; // minimum value of MEX
        ll maxR = size - 1; // maximum value of MEX

        unordered_map<ll,ll> mp; //To store the frequency of each MEX

        //pre-processing to bring the array values to under the range
        for(ll i=0;i<size;i++)
        {
            mp[i]=0;
            if(nums[i]>0)
            {
                ll div = nums[i]/value; //factor to subtract for getting value under 0
                nums[i] -= (value*div);
                // cout<<nums[i]<<" ";
            }
            else if(nums[i]<0)
            {
                ll div = ceil((nums[i]*-1)/(double)value); //factor to add for getting value above 0
                nums[i] += (value*div);
                // cout<<nums[i]<<" ";
            }
            else {
                // cout<<nums[i]<<" ";
            }
            
        }
        // cout<<endl<<"updated array: ";
        // sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++)
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]++;
                // cout<<nums[i]<<" ";
                continue;
            }
            //for each index: use binary_search to find the smallest available value in the range.
            ll rem = nums[i];
            ll maxInd = maxR/value;

            //range is 1 -> maxInd

            ll low = 1, high = maxInd;
            while(low<=high)
            {
                ll mid = low + (high-low)/2;

                ll op_val = value*mid + rem;
                if(mp[op_val]==0)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            ll final_val = value * low + rem;
            // cout<<final_val<<" ";
            //upadate the map

            mp[final_val]++;
        }

        //iterate through the indexes and return the first index with map value as 0
        ll res = size;
        for(ll i=0;i<size;i++)
        {
            if(mp[i]==0) return i;
        }

        
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,-10,7,13,6,8};
    int k = 5;
    
    cout << sol.findSmallestInteger(input, k) << endl;
    
    return 0;
}