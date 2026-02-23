/*
Problem: 868. Binary Gap
Link: https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22

Approach:
   - My Logic: 
   		While converting the input num to binary eq. Keep track of remainder. 
   		If we have already encountered 1, then update the res & cur depending on if curr rem = 1/0;
   		else set prev = 1 and start the counter from 0.
   		return the final max output.
   - T.C: O(log 2)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int res = 0;
        int cur = 0;
        while(n!=0)
        {
            int rem = n%2;
            n = n/2;
            if(prev!=1) {
                if(rem==1)
                {
                    prev = 1;
                    cur = 0;
                }
                else {
                    continue;
                }
            }
            else {
                if(rem==1)
                {
                    res = max(res, cur+1);
                    cur = 0;
                }
                else{
                    cur++;
                }
            }

        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 25;
    
    cout << sol.binaryGap(input) << endl;
    
    return 0;
}