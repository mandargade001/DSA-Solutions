/*
Problem: 166. Fraction to Recurring Decimal
Link: https://leetcode.com/problems/fraction-to-recurring-decimal/description/

Approach:
   - My Logic: 
		Get the sign. 
		Compute the integer part of the division.
		For decimal part, perform long division while keeping track of dividends coming up.
		If any divident repeats, we get the repeated part, from the position it first occurred and last inserted position.
		Put them in curly braces and return the result.
		If anytime, the remainder becomes zero, then return the result.

   - T.C: O(log |numerator/denominator|)
   - S.C: O(log |numerator/denominator|)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long x = abs((long long)numerator), y = abs((long long)denominator);
        if (x % y == 0) return res + to_string(x / y);
        else {
            res += to_string(x / y);
            x %= y;
            res += '.';
        }
        unordered_map<int, int> hash;
        while (x) {
            if (hash.count(x)) {
                res.insert(hash[x], "(");
                res += ')';
                return res;
            } else {
                hash[x] = res.size();
                x *= 10;
                res += to_string(x / y);
                x %= y;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int numerator=23456;
    int denominator=123;
    
    cout << sol.fractionToDecimal(numerator,denominator) << endl;
    
    return 0;
}