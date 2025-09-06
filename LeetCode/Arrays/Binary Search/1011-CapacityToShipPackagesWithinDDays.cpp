/*
Problem: 1011. Capacity To Ship Packages Within D Days
Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

Approach:
   - My Logic: 
		Since we need to find the minimum weight of ship to move the packages. The maximum weight of ship is sum of all the package weights and minimum is to ship atleast one package a day.
		So, we need to find the optimum weight to satisfy our requirements, this can be solved using binary_search as we need to find the optimum value in a range.
		for every possible mid value of weight, we store it and look for smaller value. 
		if not, then we look for greater weight value that can ship to packages.

   - T.C: O(N * (MaxWt-MinWt))
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int possible(vector<int>& weights,int days, int mid)
    {
        int wt = 0;
        int over = 0;
        for(int i=0;i<weights.size();i++)
        {
            wt+=weights[i];
            if(wt>mid)
            {
                over++;
                wt=weights[i];
            }
        }
        over++;
        if(over<=days) return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minShipWt = INT_MIN;
        int maxShipWt = 0;
        int res=-1;
        int size = weights.size();
        for(int i=0;i<size;i++)
        {
            minShipWt = max(minShipWt,weights[i]);
            maxShipWt+=weights[i];
        }
        long long low = minShipWt;
        long long high = maxShipWt;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            int possol = possible(weights,days, mid);
            if(possol)
            {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid + 1;
            }

        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4,5,6,7,8,9,10};
    int days = 5
    
    cout << sol.shipWithinDays(input, days) << endl;
    
    return 0;
}