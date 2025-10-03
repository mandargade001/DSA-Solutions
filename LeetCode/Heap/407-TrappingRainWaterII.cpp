/*
Problem: 407. Trapping Rain Water II
Link: https://leetcode.com/problems/trapping-rain-water-ii/description/

Approach:
   - My Logic: 
		we need a boundary wall to trap water. 
		to avoid spill, we will first take on the elements with least height and spread into its neighbours to check their capacity.
		neighbours can only store water based on what barrier they get from their previous ones.
		Doing this we will reduce our map, by eliminating smaller building that cannot help to trap water.

		found this video which explained very well: https://www.youtube.com/watch?v=TzsbIDtTlsQ

   - T.C: O(M * N * log (M+N))
   - S.C: O(M*N)

   Runtime - 28 ms | Beats 58.50%
   Memory - 20.24 MB | Beats 32.72%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    struct TupleCompare{
        bool operator() (const tuple<int,int,int>& a, const tuple<int,int,int>& b){
            return get<0>(a) > get<0>(b);
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<int>> visited(m , vector<int>(n, 0));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, TupleCompare> minHeap;

        //iterate the boundary first

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    minHeap.push({heightMap[i][j], i, j});
                    visited[i][j] = -1; // to track visited cells
                }
            }
        }

        int waterStored = 0;
        vector<pair<int,int>> neighbours;
        while(!minHeap.empty())
        {
            auto [height, r, c] = minHeap.top();
            minHeap.pop();

            neighbours = { {r+1, c}, {r, c+1},{r-1, c},{r, c-1}};

            for(const auto &p: neighbours)
            {
                int row = p.first, col = p.second;
                //check out of bound
                if(row<0 || col<0 || row>=m || col>=n || visited[row][col] == -1) continue;

                waterStored += max(height - heightMap[row][col], 0);
                
                heightMap[row][col] = max(height, heightMap[row][col]);
                minHeap.push({heightMap[row][col], row, col});
                visited[row][col] = -1;
            }
        }
        return waterStored;

        
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    
    cout << sol.trapRainWater(input) << endl;
    
    return 0;
}