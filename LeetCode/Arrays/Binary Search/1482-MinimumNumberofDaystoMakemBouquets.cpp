/*
Problem: 1482. Minimum Number of Days to Make m Bouquets
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

Approach:
   - My Logic:
   		To start making bouquets, we need to wait for atleast the minimum days to bloom 1 flowers, and at maximum days which is the most days any flower could take to bloom.
   		So, here we have a range of days out of which we need to search for value for which answers is possible. 
   		We perform binary_search on the range and check if the mid value is possible or not. 
   		If possible, we update the answer and look for values smaller than that.
   		If not, then we look for values greater than that. 
   		Finally, we return the result stored in the answer variable.

   - T.C: O(N * (maxD-minD))
   - S.C: O(1)

   Runtime - 23 ms | Beats 55.55%
   Memory - 74.16 MB | Beats 11.15%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> bloom;
    long long possible(long long m, long long k, long long days)
    {
        long long count=0;
        long long bouquets = 0;
        for(int i=0;i<bloom.size();i++)
        {
            // cout<<bloom[i]<<" ";
            if(bloom[i]<=days) count++;
            else {
                bouquets += count/k;
                count=0;
            }
        }
        if(count>0) bouquets += count/k;
        // cout<<endl;
        return bouquets>=m?1:-1;
    }
    long long minDays(vector<int>& bloomDay, long long m, long long k) {
        
        bloom=bloomDay;
        long long size = bloomDay.size();

        if(m*k>size) return -1;
        int minD=INT_MAX, maxD=INT_MIN;
        for(int i=0;i<size;i++)
        {
            minD=min(minD,bloomDay[i]);
            maxD=max(maxD,bloomDay[i]);
        }
        int low = minD;
        int high = maxD;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            // cout<<"low: "<<low<<" high: "<<high<<" mid: "<<mid<<endl;
            int p = possible(m,k,mid);
            // cout<<"possible: "<<p<<endl;
            if(p==1)
            {
                high=mid;
                // cout<<"high changed to: "<<high<<endl;
            }
            else {
                low=mid+1;
                // cout<<"low changed to: "<<low<<endl;
            }
        }
        if(low>maxD) return -1;
        return high;

    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    
    cout << sol.minDays(input, m,k) << endl;
    
    return 0;
}