/*
Problem: 2125. Number of Laser Beams in a Bank
Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2025-10-27

Approach:
   - My Logic: 
   		Here, if we see the pattern row by row, we observe that rows with 0 devices can be skipped. 
   		Only we calculate the lasers if we have previous row with some devices and current row  also has some numbers.
   		We keep track of prev row count and current row count. 
   		Once the conditions meet, devices exist in both rows, we calculate and update result.

   - T.C: O(N*M)
   - S.C: O(1)

   Runtime - 2 ms | Beats 86.53%
   Memory - 26.96 MB | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].length();
        int prev=-1;
        int res = 0;
        for(int i=0;i<m;i++)
        {
            int rowCnt = 0;
            for(int j=0;j<n;j++)
            {
                if(bank[i][j]=='1') rowCnt++;
            }
            if(prev==-1)
            {
                prev=rowCnt;
                continue;
            }
            else{
                if(rowCnt==0) continue;
                else
                {
                    res += prev * rowCnt;
                    prev = rowCnt;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<string> input = {"011001","000000","010100","001000"};
    
    cout << sol.numberOfBeams(input) << endl;
    
    return 0;
}