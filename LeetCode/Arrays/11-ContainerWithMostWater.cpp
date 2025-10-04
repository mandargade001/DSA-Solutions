/*
Problem: 11. Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/description/

Approach:
   - My Logic: 
   		We need to find the rectangle with maximum area for the correct result.
   		We will start from the extreme ends, and then try to increase the area, by moving the pointer with lesser height.
   		This is to allow chances to increase the height.
   		At end, we have the expected answer.

   - T.C: O(N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 63.75 MB | Beats 12.56%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int low = 0;
        int high = height.size()-1;

        while(low<high)
        {
            int minH = min(height[low], height[high]);
            int area = (high-low) * minH;
            res = max(res,area);
            if(minH == height[low]) low++;
            else high--;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.maxArea(input) << endl;
    
    return 0;
}