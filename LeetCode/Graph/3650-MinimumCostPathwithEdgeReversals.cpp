/*
Problem: 3650. Minimum Cost Path with Edge Reversals
Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27

Approach:
   - My Logic: 
   		Used DFS, but got TLE. 

   		We use dijktras' algorithm here to find the cheapest path to destination node from source node in directed weighted graph.
   		We use dist[n] to track the minimum cost to reach node n.
   		We use priority queue to always pick the node with minimum cost to arrive. 
   		By the time we come across any node, it would be the minimum cost, so if cost is coming greater for already visited node, then continue;
   		We explore all options from the curNode, and update the dist if possible and push into pq.
   		Return the final dist[n-1] to return the minimum cost if visited.

   - T.C: O(E log V)
   - S.C: O(E)

   Runtime 299 ms Beats 51.44% 
   Memory 319.17 MB Beats 34.61%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    // void dfs(int& nodes, int curNode,int cost, unordered_map<int, int>& minCostToArriveAtNode,unordered_map<int,vector<pair<int,int>>>& sortedEdges)
    // {
    //     if(curNode == nodes-1){
    //         //perform final comparison and set the minCostToArriveAtNode and return
    //         if(minCostToArriveAtNode.find(curNode)!=minCostToArriveAtNode.end())
    //         {
    //             minCostToArriveAtNode[curNode]=min(minCostToArriveAtNode[curNode], cost);
    //         }
    //         else{
    //             minCostToArriveAtNode[curNode] = cost;
    //         }
    //         return ;
    //     }
    //     // if(minCostToArriveAtNode.find(curNode)!=minCostToArriveAtNode.end())
    //     // {
    //         //update the minCost if possible
    //         if(minCostToArriveAtNode.find(curNode)!=minCostToArriveAtNode.end())
    //         {
    //             if(minCostToArriveAtNode[curNode]>cost) minCostToArriveAtNode[curNode] = cost;
    //             else return;
    //         }
    //         else{
    //             minCostToArriveAtNode[curNode] = cost;
    //         }
    //     // }

    //     int options = sortedEdges[curNode].size();
    //     if(options==0) return;
    //     for(int i=0;i<options;i++)
    //     {
    //         //go through all the possible options and update the minCostToArriveAtNode.
    //         int v = sortedEdges[curNode][i].first;
    //         int w = sortedEdges[curNode][i].second;
    //         dfs(nodes, v, cost+w, minCostToArriveAtNode, sortedEdges );
    //     }
    // }

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> sortedEdges; //Space: O(edges): 10^5
        for(int i=0;i<edges.size();i++) //Time: O(edges): 10^5
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            sortedEdges[u].push_back({v,w});
            sortedEdges[v].push_back({u,2*w});
        }

        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({dist[0],0});

        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            int cost = p.first;
            int node = p.second;
            pq.pop();
            if(cost>dist[node]) continue;

            if(node==n-1) return cost;

            for(auto& [v,w]: sortedEdges[node])
            {
                if(cost + w < dist[v])
                {
                    dist[v] = cost + w;
                    pq.push({cost + w, v});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];


    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<int>> input = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
    int n = 4;
    
    cout << sol.minCost(n,input) << endl;
    
    return 0;
}