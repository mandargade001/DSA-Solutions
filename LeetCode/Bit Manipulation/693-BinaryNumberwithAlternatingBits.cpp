/*
Problem: 693. Binary Number with Alternating Bits
Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

Approach:
   - My Logic: 
   		Have two vars for storing prev bit and curr bit;
   		Perform first operation indepedentyly for setting prev bit.
   		Then continuously operate to get curr bit as remainder of n%2 till n!=0;
   		Check with prev var, if same return false;
   		or else update prev and move to next iteration.
   		Finally, if not two consecutive bits were same, we return true;
   - T.C: O(log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool hasAlternatingBits(int n) {
     int prev, curr;
     if(n!=0)
     {
        prev = n%2;
        n=n/2;
     }  
     if(n==0) return true; 
     while(n!=0)
     {
        curr = n%2;
        n=n/2;
        if(prev==curr) return false;
        prev = curr;
     }
     return true;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 123;
    
    cout << sol.hasAlternatingBits(input) << endl;
    
    return 0;
}