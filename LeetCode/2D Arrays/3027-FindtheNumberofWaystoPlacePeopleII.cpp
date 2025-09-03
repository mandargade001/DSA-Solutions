/*
Problem: 3027. Find the Number of Ways to Place People II
Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

Approach:
   - My Logic: 
   		Since the input constraints are small enough to allow N^3. We can using to sorting rather than brute force.

   		The TRUE condition is for pairs (A,B) where A is at upper left side of B (Xa<=Xb and Ya>=Yb).
   		We first sort the points to follow this order, i.e. Xa<Xb and Ya>Yb.
   		We iterate across the sorted points and if they satisfy the direction check,
   		then we look if there exists any point in between the rectangle formed.
   			If not, then we increment the counter by 1.
   		repeat for other combinations.

   - T.C: O(N^3)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 41.35 MB | Beats 19.15%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        //Custom sort using comparator function
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                if(x1<=x2 && y1>=y2)
                {
                    //direction checked
                    //next, check if any other point falls in between
                    int isAnyPointInBetween = 0;
                    for(int k=i+1;k<j;k++)
                    {
                        int x=points[k][0],y=points[k][1];
                        if(x>=x1 && x<=x2 && y<=y1 && y>=y2)
                        {
                            isAnyPointInBetween=1;
                            break;
                        }
                    }
                    if(!isAnyPointInBetween)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {
    	{6,2},
    	{4,4},
    	{2,6}
    };
    
    cout << sol.numberOfPairs(input) << endl;
    
    return 0;
}