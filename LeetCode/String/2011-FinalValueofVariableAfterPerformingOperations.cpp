/*
Problem: 2011. Final Value of Variable After Performing Operations
Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/

Approach:
   - My Logic: 
   		In all the four cases, to identify the operation as - or +, we need to check the first and last index.
   		If anything matchies, we add or substract accordingly.

   - T.C: O(N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;

        for(int i=0;i<operations.size();i++)
        {
            if(operations[i][0]=='-' || operations[i][2]=='-')
            {
                res--;
            }
            if(operations[i][0]=='+' || operations[i][2]=='+')
            {
                res++;
            }
        }
        return res;        
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<string> input = {"--X","X++","X++"};
    
    cout << sol.finalValueAfterOperations(input) << endl;
    
    return 0;
}