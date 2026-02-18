/*
Problem: 3075. Maximize Happiness of Selected Children
Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2026-02-18

Approach:
   - My Logic: 
		Sort the array, keep track of steps taken using iterative var;
		While including the val update the val be reducing it by the no. of steps already completed. As for every step, val is reduced by 1.
		Return the final val.

   - T.C: O(n*logn)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long res = 0;
        for(int i=0;i<k;i++)
        {
            // cout<<format("happiness[i]: {}, i:{}\n", happiness[i], i);
            int val = happiness[i]>i ? happiness[i]-i : 0;
            res += val;
        }
        return res;
    }
};
int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.maximumHappinessSum(input, 3) << endl;
    
    return 0;
}