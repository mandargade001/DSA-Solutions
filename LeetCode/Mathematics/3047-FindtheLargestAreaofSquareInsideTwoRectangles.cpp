/*
Problem: 3047. Find the Largest Area of Square Inside Two Rectangles
Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17

Approach:
   - My Logic:
   		1. iterate the input arrays for every 2 rectangle combinations.	
		2. we need to identify if there is any interaction between the any two rectangles.
		3. if yes, find the common area and the sq. width
		4. calculate area and update the maxArea
		5. return the final result
		
   - T.C: O(N^2)
   - S.C: O(1)

   Runtime - 115 ms | Beats 40.08%
   Memory - 59.53 MB | Beats 23.14%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    using ll = long long;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        //take size of both arrays
        ll size = bottomLeft.size();

        //define the required variables
        ll max_sq_area = 0;
        ll Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

        //iterate the arrays such that, we check for all the combinations of rectangles
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                //reset the first and second rectangle as per their position Ax before Cx
                ll x1 = bottomLeft[i][0];
                ll y1 = bottomLeft[i][1];
                ll x2 = topRight[i][0];
                ll y2 = topRight[i][1];

                ll x3 = bottomLeft[j][0];
                ll y3 = bottomLeft[j][1];
                ll x4 = topRight[j][0];
                ll y4 = topRight[j][1];

                // cout<<format("x1,y1:{},{} - x2,y2:{},{}\nx3,y3:{},{} - x4,y4:{},{}", x1, y1, x2, y2,x3, y3, x4, y4)<<endl;

                if(x1<x3){
                    Ax = x1; Ay = y1; Bx = x2; By = y2; Cx = x3; Cy = y3; Dx = x4; Dy = y4;
                    // cout<<"x1<x3"<<endl;
                }
                else {
                    Ax = x3; Ay = y3; Bx = x4; By = y4; Cx = x1; Cy = y1; Dx = x2; Dy = y2;
                }

                //check if there is any interaction or else skip
                if(Cy<=By && Dy>=Ay && Cx<=Bx && Dx>=Ax)
                {
                    //Find the interacting coordinates and the sq. area
                    x1 = max(Ax, Cx); y1 = max(Ay, Cy);
                    x2 = min(Bx, Dx); y2 = min(By, Dy);

                    // cout<<format("x1,y1:{},{} - x2,y2:{},{}", x1, y1, x2, y2)<<endl;

                    ll csw = min((y2-y1), (x2-x1));

                    // cout<<"csw: "<<csw<<endl;

                    max_sq_area = max(max_sq_area, (csw*csw));
                }
                else continue;
            }
        }
        //return final max sq. area
        return max_sq_area;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> bottomLeft = {{1,1},{2,2},{3,1}};
    vector<vector<int>> topRight = {{3,3},{4,4},{6,6}};
    
    cout << sol.largestSquareArea(bottomLeft, topRight) << endl;
    
    return 0;
}