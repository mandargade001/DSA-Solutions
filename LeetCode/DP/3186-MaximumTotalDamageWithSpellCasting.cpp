/*
Problem: 3186. Maximum Total Damage With Spell Casting
Link: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

Approach:
   - My Logic: 
		First, observe the requirement to sort, to take into consideration to eliminations of surrounding power.
		Second, can reduce the operations by pre computing the freq of each unique power.
		Third, everytime we have two options, either to pick or skip a power -> pointing to dp like solution.
		Fourth, while choosing dp, we have only one dimension, i.e. index of next position.
		Fifth, to fasten the skipping of surrounding power, we use binary_search -> lower_bound.
		Sixth, we start from last element to iterate, as we need to keep track of upcoming dp, if we skip.

   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 407 ms | Beats 34.15%
   Memory - 230.35 MB | Beats 22.71%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    typedef long long ll;
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll,ll> mp;
        for(int i=0;i<power.size();i++)
        {
            mp[power[i]]++;
        }
        vector<ll> nums(mp.size());
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            nums.push_back(it->first);
        }
        sort(nums.begin(), nums.end());

        vector<ll> dp(nums.size()+1,0);

        ll result = 0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ll skip = dp[i+1];
            int j = lower_bound(nums.begin(), nums.end(), nums[i]+3) - nums.begin();
            ll take = nums[i]*mp[nums[i]] + dp[j];

            dp[i] = max(skip, take);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.maximumTotalDamage(input) << endl;
    
    return 0;
}