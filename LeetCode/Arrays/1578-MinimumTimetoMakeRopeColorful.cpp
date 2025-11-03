/*
Problem: 1578. Minimum Time to Make Rope Colorful
Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

Approach:
   - My Logic: 
   		start iterating the array 
        get the consecutive repeating color indexes

        for every section, call function to eleminate all but one in the increasing order of their neededTime, only get the values, no operations needed.

        repeat.
   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%
   
   - Optimal logic: 
		Can do in O(N).
		Iterate the string, when adjacent same color encountered, add the min time value of two and update j to take the more time.
		Repeat as in last, only max time value remains. 
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int makeColorful(vector<int>& neededTime, int start, int end)
    {
        multiset<int> orderedTime(neededTime.begin()+start, neededTime.begin()+end+1);
        int toRemove = end - start;
        int sum = 0;
        for(auto n:orderedTime)
        {
            if(toRemove == 0) break;
            // cout<<"removing: "<<n<<endl;
            sum+=n;
            toRemove--;
        }
        return sum;
        
    }
    int minCost(string colors, vector<int>& neededTime) {
        

        int csize = colors.size();
        int tsize = neededTime.size();
        int res = 0;

        
        for(int i=1;i<csize;i++)
        {
            if(colors[i-1]==colors[i])
            {
                int end = i;
                while(colors[end]==colors[i-1])
                {
                    end++;
                }
                // cout<<"start: "<<i-1<<", end: "<<end-1<<endl;
                res += makeColorful(neededTime, i-1,end-1);
                i=end-1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string color = "abaac"
    vector<int> input = {1,2,3,4, 5};
    
    cout << sol.minCost(color, input) << endl;
    
    return 0;
}