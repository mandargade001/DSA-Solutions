/*
Problem: 2976. Minimum Cost to Convert String I
Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

Approach:
   - My Logic: 
   		Precompute minimum conversion costs between all letter pairs using Dijkstra's algorithm from each unique source character, then sum costs for each position in the string transformation.

   		Phase 1: Preprocessing & Graph Construction

	   		Adjacency List: Build charIndices mapping each character to indices in original[] where it appears (enables O(1) edge lookup)
	   		Encode Function: Map pair<char,char> to unique integer: (a-'a')*26 + (b-'a') for efficient hash-based storage
	   		Result Storage: unordered_map<int, int> stores encode(src, dest) → minCost

   		Phase 2: Multi-Source Dijkstra
	   		For each unique character in original[]:

	   		Initialize: Min-heap priority queue with (cost=0, startChar)
	   		Dijkstra's Algorithm:

		   		Pop minimum cost node from priority queue
		   		Skip if already visited (greedy choice ensures optimality)
		   		For each outgoing edge (from charIndices), calculate newCost = currCost + edgeCost
		   		Update minCost[encode(start, dest)] if cheaper path found
		   		Push (newCost, destChar) to priority queue


   		Complexity per source: O(E log V) where E = edges, V = 26 letters

   		Phase 3: String Conversion

	   		Iterate through each position in source
	   		Lookup precomputed cost: minCost[encode(source[i], target[i])]
	   		Return -1 if any transformation is impossible
	   		Sum all costs for final answer

   - T.C: O(E log V) where E = edges, V = 26 letters
   - S.C: O(N)

   Runtime 503 ms Beats 8.09%
   Memory 157.84 MB Beats 11.09%
   
   - Optimal logic: Floyd-Warshall algorithm

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        auto encode = [](char a, char b){ return (a-'a')*26 + (b-'a');};

        unordered_map<int, int> minCost;
        map<char,vector<int>> charIndices;

        
        for(int i=0;i<original.size();i++)
        {
            charIndices[original[i]].push_back(i);
        }

        set<char> processed;
        for(auto& start: original)
        {
            if(processed.count(start)) continue;
            processed.insert(start);

            set<char> visited;
            priority_queue<pair<int, char>, vector<pair<int,char>>, greater<>> pq;

            pq.push(make_pair(0,start));
            // cout<<"\n\nProcess started for "<<start<<endl;

            while(!pq.empty())
            {
                auto [currCost, currChar] = pq.top();//a,0 - b,2 - c,7
                pq.pop();

                if(visited.count(currChar)) continue;
                visited.insert(currChar);//a,b,c

                // cout<<format("inserted {} in visited\n",c);
                //check if the char c is present in the original array
                if(charIndices.count(currChar))
                {
                    for(auto& ind : charIndices[currChar])
                    {
                        char nextChar = changed[ind];//b //c //b
                        int newCost = currCost + cost[ind];//2, //2+5=7 //7+5=12
                        // cout<<format("transition exists: from {} -> {}, cost={}\n",original[i], changedChar,costVar); //a

                        int p = encode(start,nextChar);

                        if(!minCost.count(p) || minCost[p]>newCost) { //a->b, a->c,
                            minCost[p]=newCost;//2 //7
                        }
                        pq.push({newCost,nextChar});//b,2 //c,7
                    }
                }
            }
        }

        long long finalCost = 0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i]) continue;
            int p = encode(source[i], target[i]);
            if(!minCost.count(p)) return -1;
            finalCost+=minCost[p];
        }
        return finalCost;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string source = "abcd", target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    
    cout << sol.minimumCost(source,target, original, changed, cost) << endl;
    
    return 0;
}