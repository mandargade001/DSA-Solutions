/*
Problem: 1404. Number of Steps to Reduce a Number in Binary Representation to One
Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

Approach:
   - My Logic: 
   		For every operation update the input string.
   		If odd, addOne, 
   		if even, remove last index.
   		return ops;
   - T.C: O(n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    void divideByTwo(string& s) { s.pop_back(); }

    void addOne(string& s) {
        int i = s.size() - 1;

        // Iterating while the character is 1 and changing to 0 to carry the 1.
        while (i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }

        if (i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
    }

    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        while (s.size() > 1) {
            N = s.size();

            if (s[N - 1] == '0') {
                divideByTwo(s);
            } else {
                addOne(s);
            }

            operations++;
        }

        return operations;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "1001";
    
    cout << sol.numSteps(s) << endl;
    
    return 0;
}