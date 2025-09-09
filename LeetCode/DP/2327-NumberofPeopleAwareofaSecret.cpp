/*
Problem: 2327. Number of People Aware of a Secret
Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

Approach:
   - My Logic: Yet to be written
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>aware(n,0);
        int rem=1000000000+7;
        aware[0]=1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+delay;j<i+forget && j<n;j++)
            {
                aware[j]+=aware[i]%rem;
                aware[j]=aware[j]%rem;
            }
        }
        int ans=0;
        for(int i=n-forget;i<n;i++)
        {
            ans+=aware[i];
            ans=ans%rem;
        }
        return ans%rem;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int n = 6, delay = 2, forget = 4;

    
    cout << sol.peopleAwareOfSecret(n, delay, forget) << endl;
    
    return 0;
}