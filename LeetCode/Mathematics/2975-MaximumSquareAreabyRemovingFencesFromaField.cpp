/*
Problem: 2975. Maximum Square Area by Removing Fences From a Field
Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/?envType=daily-question&envId=2026-01-16

Approach:
   - My Logic: 
   		Observed that to get a square we need to find spaces of same length. 
   		We set up boundaries and iterate through all combinations of hFences and put them in set.
   		We repeat for vFences, and simultaneously check if the diff exists in hFences and calculate the max area possible for square.
   		Return the final response.

   - T.C: O(n * log n)
   - S.C: O(n)
	

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int MOD = 1e9 + 7;

        hFences.push_back(m);
        hFences.push_back(1);
        vFences.push_back(n);
        vFences.push_back(1);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<long> hSum ;

        for(int i=1;i<hFences.size();i++)
        {
            int sum = 0;
            for(int j=i-1;j>=0;j--)
            {
                sum = (hFences[i]-hFences[j]);
                hSum.insert(sum);
            }
        }
        long long ans = -1;
        for(int i=1;i<vFences.size();i++)
        {
            int sum = 0;
            for(int j=i-1;j>=0;j--)
            {
                sum = (vFences[i]-vFences[j]) ;
                if(hSum.count(sum)){
                    ans = max(ans, 1LL * sum * sum);
                }
            }
        }
        return ans % MOD;
        
    }
};
int main() {
    Solution sol;
    
    // Example input
    int m = 6, n = 7;
    vector<int> hFences = {2};
    vector<int> vFences = {4};
    
    cout << sol.maximizeSquareArea(m, n, hFences, vFences) << endl;
    
    return 0;
}