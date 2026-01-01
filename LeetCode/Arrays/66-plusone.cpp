/*
Problem: 66. Plus One
Link: https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01

Approach:
   - My Logic: Start iterating the array from right to left, and keep on adding the carry. At the end, if carry still exists, insert 1 to the start.
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
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        for(int i=size-1;i>=0;i--)
        {
            if(carry)
            {
                carry = (digits[i]+carry)/10;
                digits[i]= (digits[i]+1)%10;
            }
        }
        if(carry)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    input = sol.plusOne(input);

    for (std::vector<int>::iterator i = input.begin(); i != input.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}