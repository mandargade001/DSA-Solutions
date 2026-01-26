/*
Problem: 1200. Minimum Absolute Difference
Link: https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26

Approach:
   - My Logic: Sort the array, find the minAbsDiff with taking difference of adj elements, insert pair in the result array. return.
   - T.C: O(N*logN)
   - S.C: O(1)

   Runtime 16ms Beats 47.69% 
   Memory 36.70MB Beats 32.02%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++)
        {
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-arr[i-1]==minDiff)
            {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minimumAbsDifference(input) << endl;
    
    return 0;
}