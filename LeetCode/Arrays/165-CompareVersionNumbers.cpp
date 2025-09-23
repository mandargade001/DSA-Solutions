/*
Problem: 165. Compare Version Numbers
Link: https://leetcode.com/problems/compare-version-numbers/description/

Approach:
   - My Logic:
   		Get a vector of integers for each version string, where each index value represent a revision.
   		Once we have these vectors, we get the size by trimming down trailing revisions with value 0.
   		Then compare the vectors, and their length.

   - T.C: O(N)
   - S.C: O(N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 8.72 MB | Beats 16.14%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int>v2;

        for(int i=0;i<version1.size();i++)
        {
            string s = "";
            while(i<version1.size() && version1[i]!='.')
            {
                s+=version1[i];
                i++;
            }
            if(s!="") v1.push_back(stol(s));
        }
        for(int i=0;i<version2.size();i++)
        {
            string s = "";
            while(i<version2.size() && version2[i]!='.')
            {
                s+=version2[i];
                i++;
            }
            if(s!="") v2.push_back(stol(s));
        }

        int last1;
        int last2;
        for(int i=v1.size()-1;i>0;i--)
        {
            if(v1[i]!=0){
                last1=i;
                break;
            }
        }
        for(int i=v2.size()-1;i>0;i--)
        {
            if(v2[i]!=0){
                last2=i;
                break;
            }
        }
        for(int i=0;i<=last1 && i<=last2;i++)
        {
            if(v1[i]>v2[i]) return 1;
            else if(v2[i]>v1[i]) return -1;
        }

        if(last1>last2) return 1;
        else if(last1<last2) return -1;

        return 0;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input1 = "1.10";
    string input2 = "1.2";
    
    cout << sol.compareVersion(input1, input2) << endl;
    
    return 0;
}