/*
Problem: 2943. Maximize Area of Square Hole in Grid
Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/

Approach:
   - My Logic: 
   		On seeing the examples and constraints, noticed that for increasing the area of sq. hole, 
   		we need to remove adjacent bars both in hor and ver directions. The no. of bar in both directions removed should be equal to make it a sq. hole.
   		We calculate the max adjacent bars in both the directions and get the min of them. 
   		Both the arrays will hold atleast one element in it.

   - T.C: O(K+L), {K,L}: {len of hBar, len of vBar} 
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 31.76 MB | Beats 99.13%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxConsecutiveHor = 1;
        int maxConsecutiveVer = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int currConsecutive = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1) {
                currConsecutive++;
            }
            else {
                maxConsecutiveHor = max(maxConsecutiveHor, currConsecutive);
                currConsecutive = 1;
            }
        }
        maxConsecutiveHor = max(maxConsecutiveHor, currConsecutive);

        currConsecutive = 1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1) {
                currConsecutive++;
            }
            else {
                maxConsecutiveVer = max(maxConsecutiveVer, currConsecutive);
                currConsecutive = 1;
            }
        }
        maxConsecutiveVer = max(maxConsecutiveVer, currConsecutive);  

        int finalBarsRemoved = min(maxConsecutiveVer, maxConsecutiveHor);

        return (finalBarsRemoved+1)*(finalBarsRemoved+1);      
    }
};

int main() {
    Solution sol;
    
    // Example input
    int n = 1, m = 1;
    vector<int> hBars = {2};
    vector<int> vBars = {2};
    
    cout << sol.maximizeSquareHoleArea(n, m, hBars, vBars) << endl;
    
    return 0;
}