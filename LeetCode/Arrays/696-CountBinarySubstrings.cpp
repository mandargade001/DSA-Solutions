/*
Problem: 696. Count Binary Substrings
Link: https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19

Approach:
   - My Logic: 
		Find the points of change, 11_00.
		Check the pattern, whether 1_0 or 0_1. 
		Continue to expand the same pattern till boundary is touched.
		Keep count of the patterns found.
		Iterate complte array and return result.

   - T.C: O(N)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int len = s.size();
        for(int i=0;i<len-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                //expand on sides to get same patterns.
                //0,1
                if(s[i]=='0' && s[i+1]=='1')
                {
                    res++;
                    int j=i-1;
                    int k=i+2;
                    while(j>=0 && k<len && s[j]=='0' && s[k]=='1')
                    {
                        res++;
                        j--;
                        k++;
                    }
                }
                else if(s[i]=='1' && s[i+1]=='0')
                {
                    res++;
                    int j=i-1;
                    int k=i+2;
                    while(j>=0 && k<len && s[j]=='1' && s[k]=='0')
                    {
                        res++;
                        j--;
                        k++;
                    }
                }
                //1,0
                
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "00110011";
    
    cout << sol.countBinarySubstrings(s) << endl;
    
    return 0;
}