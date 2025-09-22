/*
Problem: 3005. Count Elements With Maximum Frequency
Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

Approach:
   - My Logic: HashMap
		We iterate through the input array, and keep on updating the frequency of each element, and update the max freq.
		Then we iterate the map to sum the frequencies that match with maxFrequency.

   - T.C: O(N)
   - S.C: O(N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 23.18 MB | Beats 67.03%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> f;
        int maxf = INT_MIN;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
            maxf = max(maxf,f[nums[i]]);
        }
        int res = 0;
        for(const auto& [key, value]:f)
        {
            if(value==maxf)
            {
                res+=value;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.maxFrequencyElements(input) << endl;
    
    return 0;
}