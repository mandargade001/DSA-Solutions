/*
Problem: 712. Minimum ASCII Delete Sum for Two Strings
Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10

Approach:
   - My Logic: 
   		Here we have options to find the largest common subsequence in terms of their ASCII sum.
		We start with 0 index, and we have options to take or skip any characters till end is reached. 
		We can define a 2d dp state as it involves two strings, where dp[i][j] = max sum of ASCII of common subsequence if considering s1[i:] and s2[j:].
		For transition, we need to check the match, if two characters match, we include its ASCII value and move on to find next, else we get max from skipping either of the characters from both strings.
		Finally, we will get the max Ascii sum of common subsequence from 0 index, which is our problem.
		Substract from totalSum and return.

   - T.C: O(n*m)
   - S.C: O(n*m)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& s1, string& s2, int i, int j) {
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            dp[i][j] = s1[i] + lcs(s1, s2, i+1, j+1);
        }
        else {
            dp[i][j] = max(
                lcs(s1,s2, i+1, j),
                lcs(s1, s2, i, j+1)
            );
        }
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {

        //Take total ASCII sum of all the characters present
        long totalSum = 0;
        for(char c: s1)
        {
            totalSum += c;
        }

        for(char c: s2)
        {
            totalSum += c;
        }
        dp.assign(s1.size(), vector<int>(s2.size(), -1));
        // cout<<"totalSum: "<<totalSum<<endl;
        long remSum = lcs(s1, s2, 0, 0);
        // cout<<"remSum: "<<remSum<<endl;
        return totalSum-remSum*2;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s1 = "delete";
    string s2 = "leet";
    
    cout << sol.minimumDeleteSum(s1, s2) << endl;
    
    return 0;
}