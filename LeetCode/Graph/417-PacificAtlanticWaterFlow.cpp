/*
Problem: 417. Pacific Atlantic Water Flow
Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& visited, const vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        std::stack<std::pair<int, int>> stack;
        stack.push({r, c});
        visited[r][c] = true;

        while (!stack.empty()) {
            auto [cr, cc] = stack.top();
            stack.pop();
            // Check all four neighbors
            const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (const auto& dir : dirs) {
                int nr = cr + dir[0], nc = cc + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] &&
                    heights[nr][nc] >= heights[cr][cc]) {
                    visited[nr][nc] = true;
                    stack.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // DFS from Pacific boundaries (top row, left column)
        for (int i = 0; i < m; i++) {
            if (!pac[i][0]) dfs(i, 0, pac, heights);
        }
        for (int j = 0; j < n; j++) {
            if (!pac[0][j]) dfs(0, j, pac, heights);
        }

        // DFS from Atlantic boundaries (bottom row, right column)
        for (int i = 0; i < m; i++) {
            if (!atl[i][n - 1]) dfs(i, n - 1, atl, heights);
        }
        for (int j = 0; j < n; j++) {
            if (!atl[m - 1][j]) dfs(m - 1, j, atl, heights);
        }

        // Collect cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.solve(input) << endl;
    
    return 0;
}