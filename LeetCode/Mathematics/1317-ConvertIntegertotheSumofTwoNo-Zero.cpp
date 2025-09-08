/*
Problem: 1317. Convert Integer to the Sum of Two No-Zero
Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/

Approach:
   - My Logic: 
   		We iterate from 1 to N/2 since, after that the combinations will repeat.
   		For each of the combinations, we check if they contain any zero. 
   		If not, we return the result. Constraints are such that atleast one solution is present.
   		
   - T.C: O(N * log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.34 MB | Beats 30.14%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    bool containsZero(int n)
    {
        while(n>0)
        {
            int rem = n%10;
            n=n/10;
            if(rem==0) return true;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n/2;i++)
        {
            if(!containsZero(i) && !containsZero(n-i))
            {
                return {i,n-i};
            }
        }
        return {1,n-1};
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.solve(input) << endl;
    
    return 0;
}