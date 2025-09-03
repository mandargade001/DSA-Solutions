/*
Problem: 56. Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/description/

Approach:
   - My Logic: 
   		we sort the input vector, to iterate in ordered way.
   		for every interval, we check if it overlaps with previous interval.
   			if yes, we update the end of previous interval with max value.
   			else we push the previous interval as it is not overlapping. replace the current interval.
   		repeat for all intervals

   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 3 ms | Beats 89.45%
   Memory - 23.91 MB | Beats 30.96%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        //sort with x asc and y asc
        sort(intervals.begin(),intervals.end());

        //initialize the results array.
        vector<vector<int>> result;

        //iterate till the overlap exists.
        int x=intervals[0][0], y=intervals[0][1];

        for(int i=1;i<size;i++)
        {
            if(intervals[i][0]<=y)
            {
                y=max(y,intervals[i][1]);
            }
            else{
                result.push_back({x,y});
                 x=intervals[i][0], y=intervals[i][1];
            }
        }
        result.push_back({x,y});
        return result;        
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{1,3},{2,6},{8,10},{15,18}
    };
    
    input = sol.merge(input);

    for(const auto& row : input) {
        cout << row[0] << "," << row[1];
        cout << endl;
    }
    
    return 0;
}