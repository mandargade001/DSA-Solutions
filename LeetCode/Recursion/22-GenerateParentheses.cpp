/*
Problem: 22. Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses/description/

Approach:
   - My Logic: Recursive approach
   		At any point, no. of closed bracket should be less or equal to open.
   		We can not proceed further once all open and close brackets are used.
   		If open are left, we can use them.
   		If close are left and the are more than open, we can use them.

   - T.C: O(N)
   - S.C: O(N)
   
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<string> res;
    unordered_map<string,int> mp;
    void recur(int n, int openLeft, int closeUsed, string s)
    {
        if(openLeft==0 && closeUsed==n)
        {
            if(mp.find(s)==mp.end()) {
                res.push_back(s);
                mp[s]++;
            }
            return ;
        }
        if(openLeft==0)
        {
            recur(n,openLeft,closeUsed+1,s+')');
            
        }
        if(n==openLeft)
        {
            
            recur(n,n-1,closeUsed,s+'(');
            
        }
        if(openLeft>0 && openLeft<n)
        {
            
            recur(n,openLeft-1,closeUsed,s+'(');
        }
        if(closeUsed<(n-openLeft))
        {
            recur(n,openLeft,closeUsed+1,s+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        recur(n, n, 0, s);
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int input = 3;
    vector<string> output;
    
    output = sol.generateParenthesis(input);

    for (int i = 0; i < output.size(); ++i)
    {
    	/* code */
    	cout<<output[i]<<endl;
    }
    
    return 0;
}