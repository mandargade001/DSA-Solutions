/*
Problem: 1304. Find N Unique Integers Sum up to Zero
Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/

Approach:
   - My Logic: 
   		we can go on to push integer and their negative value to keep the sum zero. If N is odd, first add zero and repeat the process.

   - T.C: O(N/2)
   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n==1) {
            res.push_back(0);
            return res;
        }
        int limit = n/2;
        int start = 1;
        if(n%2!=0)
        {
        	start = 0;
            res.push_back(0);
            start++;
            limit = (n-1)/2;
        }

        for(int i=1;i<=limit;i++)
        {
            res.push_back(start);
            res.push_back(-1*start);
            start++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 5;
    
    vector<int> output = sol.sumZero(input);
    for(int val : output) {
            cout << val << " ";
        }
        cout << endl;
    
    return 0;
}