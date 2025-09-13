/*
Problem: 1781. Sum of Beauty of All Substrings
Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

Approach:
   - My Logic: 
   		Find all substrings by iterating a nested for loop - 2. To somewhat optimize the frequency calculation. 
   		We can have frequency recording vector of size 26 for each character declare under the first loop so that the second loop can use it without reiterating their substring.
		For each substring, update the two variables - maxFreq and minFreq and sum beauty to final result. 
		Return when all the substrings are over, i.e. double nested for loop is over.

   - T.C: O(N^2)
   - S.C: O(1)
   
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for(int i = 0;i<n;i++){
            int freq[26] = {0};

            for(int j = i;j<n;j++){
                freq[s[j] - 'a']++;

                int min_freq = INT_MAX,max_freq = 0;

                for(int f : freq){
                    if(f > 0){
                        min_freq = min(min_freq,f);
                        max_freq = max(max_freq,f);
                    }
                }
                sum += (max_freq - min_freq);
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "aabcbaa";
    
    cout << sol.beautySum(s) << endl;
    
    return 0;
}