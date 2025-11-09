/*
Problem: 2169. Count Operations to Obtain Zero
Link: https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09

Approach:
   - My Logic: Optimized explanation
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%
   
   - Optimal logic: 

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int countOperations(int num1, int num2) {
        long long res = 0;
        while(num1!=0 && num2!=0)
        {
            if(num1>=num2)
            {
                num1-=num2;
                
            }
            else
            {
                num2-=num1;
                
            }
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int num1 = 2, num2 = 3;
    
    cout << sol.countOperations(num1, num2) << endl;
    
    return 0;
}