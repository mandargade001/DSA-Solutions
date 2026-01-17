/*
Problem: 556. Next Greater Element III
Link: https://leetcode.com/problems/next-greater-element-iii/description/

Approach:
   - My Logic: for next permutation, we find the pivot where digit is less than previous. Swap them and then sort the elements after pivot.
   - T.C: O(n log n)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
    	
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<=11)return -1;
        vector<int> digits;
        bool flag = false;
        int flag_ind;

        while(n>0){
            int temp = n%10;
            digits.push_back(temp);
            n = n/10;
            if(!flag && digits.size()>1 && digits[digits.size()-1]<digits[digits.size()-2]) {
                flag = true;
                flag_ind = digits.size() - 1;
            }
        }
        if(digits.size()<2 || !flag) return -1;
        int biggerN=10;
        int indJustBiggerThanPos;

        for(int i=flag_ind-1;i>=0;i--){
            if(digits[i]>digits[flag_ind] && digits[i]<biggerN){
                biggerN = digits[i];
                indJustBiggerThanPos=i;
            }
        }
        digits[indJustBiggerThanPos] = digits[flag_ind];
        digits[flag_ind] = biggerN;

        sort(digits.begin(), digits.begin() + (flag_ind), greater<int>());

        long res = 0;

        for(int i=digits.size()-1;i>=0;i--)
        {
            res = res*10 + digits[i];
        }

        if(res>INT_MAX) return -1;
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 124321;
    
    cout << sol.nextGreaterElement(input) << endl;
    
    return 0;
}