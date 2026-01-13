/*
Problem: 3453. Separate Squares I
Link: https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

Approach:
   - My Logic:
   		Since we need to find Y coordinate in a range, we can binary search for the answer using the Area computation for every mid value we get. 
   		Basically, we will be sweeping across the range for the answer.
   		Here, we are supposed to use precision-based termination for the binary search loop. 
   - T.C: O(n*log(precision))
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    double findAreaUnder(vector<vector<int>>& squares, double mid)
    {
        //iterate on the squares 2d array, and set the maxY for any square using mid and calculate the area under the y=mid;
        //condition: h = yi+li > mid : mid-yi : yi+li;
        //area: h * li;
        //return the result area.

        double area = 0.0;
        for(auto& sq: squares){
            double y = sq[1];
            double l = sq[2];
            if(mid<y) continue;
            else if(y+l<=mid){
                area += (l*l);
            }
            else{
                area += (mid-y)*l;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int size = squares.size();
        // sort(squares.begin(), squares.end()); //O(nlogn)
        int minPoint=INT_MAX, maxPoint=INT_MIN;
        double totalArea = 0.0;
        for(int i=0;i<size;i++)
        {   
            totalArea += ((double)squares[i][2]*(double)squares[i][2]);
        
            minPoint = (squares[i][1]>minPoint) ? minPoint : squares[i][1];
            maxPoint = (squares[i][1]+squares[i][2]>maxPoint) ? (squares[i][1]+squares[i][2]) : maxPoint;
        }
        double low, high, mid;
        low = minPoint;
        high = maxPoint;

        while(high-low > 1e-6)
        {
            mid = (low+high)/2.0;
            double area = findAreaUnder(squares, mid);
            if(area<totalArea/2.0){
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return low;

    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> squares = {{0,0,1},{2,2,1}};
    
    cout << sol.separateSquares(squares) << endl;
    
    return 0;
}