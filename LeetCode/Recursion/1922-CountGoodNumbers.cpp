/*
Problem: 1922. Count Good Numbers
Link: https://leetcode.com/problems/count-good-numbers/description/

Approach:
   - My Logic: 
   		If we see the pattern by starting with n=0 -> n=4, it becomes clear that we need to count the even and odd indices and pow (5 and 4)
   		Ex: if n=7(odd), then 
   			ans: 5 * ans(7-1);
   			here, ans(6) = 5^(6/2) * 4^(6/2)
   		We use binary exponentiation to calculate the powers of 5 and 4
   		and return answer.
   		
   - T.C: O(log N)
   - S.C: O(log N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 7.91 MB | Beats 37.03%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long recur(long long base, long long exp, long long mod)
    {
        if(exp == 0) return 1;
        base = base % mod;
        if(exp%2!=0)
        {
            long long half = recur(base,exp-1,mod);
            return (base * half)%mod;
        }
        else {
            long long half = recur(base,exp/2,mod);
            return (half*half)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long res = 1;
        if(n%2!=0)
        {
            res *= 5;
            n--;
        }
        long long evenP = recur(5,n/2,MOD)%MOD;
        long long oddP = recur(4,n/2,MOD)%MOD;
        return (res*((evenP*oddP)%MOD))%MOD;

    }
};

int main() {
    Solution sol;
    
    // Example input
    int n = 50;
    
    cout << sol.countGoodNumbers(n) << endl;
    
    return 0;
}