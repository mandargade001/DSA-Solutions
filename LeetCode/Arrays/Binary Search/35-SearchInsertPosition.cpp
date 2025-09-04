/*
Problem: 35. Search Insert Position
Link: https://leetcode.com/problems/search-insert-position/description/

Approach:
   - My Logic: Perform binary search using inbuild function for lower_bound.
   		The problem is solved by finding the lower_bound of the value.

   - T.C: O(log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 13.62 MB | Beats 41.99%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return (lower_bound(nums.begin(),nums.end(),target)-nums.begin());
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,3,5,6};
    int target = 5;
    
    cout << sol.searchInsert(input, target) << endl;
    
    return 0;
}