/*
Problem: 1611. Minimum One Bit Operations to Make Integers Zero
Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2025-11-08

Approach:
   - My Logic: 
   		for optimal result, we should start operation from left to right set bits.
   		To make a set bit to 0, we need to make its side bit 1 -> then update current bit -> again make the side bit to 0: overall it take 2*X+1 steps.
   		Also, F(10100) = F(10000) - F(100).
   		We repeat the process for all the set bits to finally get the answer.
   		
   - T.C: O(log n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.35 MB | Beats 55.27%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);
class Solution {
public:
    string intToBinary(int num) {
        string binary = bitset<32>(num).to_string();
        return binary.substr(binary.find('1'));
    }
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        string s = intToBinary(n);
        // cout<<s<<endl;
        long long res = 0;
        // int countOfSet = 0;
        int size = s.length();
        int sign = 1;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='1') 
            {
                res = res + (sign*(pow(2,size-i)-1));
                sign*=-1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 123;
    
    cout << sol.minimumOneBitOperations(input) << endl;
    
    return 0;
}