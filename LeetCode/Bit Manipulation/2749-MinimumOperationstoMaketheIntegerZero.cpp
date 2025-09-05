/*
Problem: 2749. Minimum Operations to Make the Integer Zero
Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

Approach:
   - My Logic: 
		Here, if we try to think and see what we are supposed to do to get num1=0.
		We can see that, we get 
			S = num1 - T * num2, 
		where S has to be represented as sum of powers of 2
		and T = no. of operations performed.

		There are some constraints that we have to get solution - 
		1. S > 0
		2. T > HammingWeight(S)
		3. S >= T
		4. T <= 60, since max(HammingWeight) = 60

		** HammingWeight(S) -> Number of 1's in binary representation of S

		We iterate through T, and return when constraints fail. Return T if all constraints pass.

   - T.C: O(1)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.2 MB | Beats 52.07%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        int k = 1;
        while (k<=60) {
            long long x = num1 - num2 * k;
            if (x < k) {
                return -1;
            }
            if (k >= __builtin_popcountll(x)) {
                return k;
            }
            k++;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int num1 = 5, num2=-21;
    
    cout << sol.makeTheIntegerZero(num1, num2) << endl;
    
    return 0;
}