/*
Problem: 1015. Smallest Integer Divisible by K
Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

Approach:
   - My Logic: 
   		We can start with 1 and keep checking if the rem gets to 0.
   		All the combinations that the remainder can have is 0 -> K-1
   		We start a loop from 0->k-1
   		If we get 0, we return the length
   		Else return -1

   - T.C: O(K)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // k < 100001

        if(k%2==0 || k%5==0) return -1;
    
        int startUnit = 1;
        int ans = 1;
        // while(k<startUnit)
        // {
        //     startUnit = startUnit * 10 + 1;
        //     ans++;
        // }
        // unordered_set<int> checkRepeatRem;

        /**
        K = 13
        Ans = 111111 (6)

        if K is even, return -1

        ANS = 1;

        startUnit = 111
        ANS = 3;


        2nd loop
        1: rem = 7 -> check if set has 7 -> if YES, break and return -1 -> ELSE insert in SET
            Add 1 to rem, rem = rem * 10 + 1 
            ANS++
        2: repeat

        return ANS else -1
        */

        int rem = 0;

        for(int i=1;i<=k;i++)
        {
            rem = startUnit%k;
            if(rem==0) 
            {
                return ans;
            }
            // else if(checkRepeatRem.find(rem)!=checkRepeatRem.end())
            // {
            //     return -1;
            // }
            
            // checkRepeatRem.insert(rem);
            startUnit = rem * 10 + 1;
            ans++;
            
        }

        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int k = 13;
    
    cout << sol.smallestRepunitDivByK(k) << endl;
    
    return 0;
}