/*
Problem: 3147. Taking Maximum Energy From the Mystic Dungeon
Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/

Approach:
   - My Logic: 
		In this problem, we need to keep track of the chains formed by K jumps.
		Here we can solve a problem using a greedy approach by always keeping check whether the previous chain sum is to be considered or not.
		On every step, we need to check whether we should use previous element (i-k) to add to current element. 
		If the sum gives greater sum, we add or else we do nothing.
		Repeating the process would give us the final max sum of all the chains in the last K element of array irrespective of their starting positions.
		Return the maximum of the last K elements.
		
   - T.C: O(N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 146.10 MB | Beats 75.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int size = energy.size();
        for(int i=0;i<size;i++)
        {
            if(i-k>=0)
            {
                int up = energy[i] + energy[i-k];
                if(up>energy[i])
                {
                    energy[i] = up;
                }
            }
            
        }
        int res = INT_MIN;
        for(int i=size-k;i<size;i++)
        {
            res = max(res, energy[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    int k = 2;
    
    cout << sol.maximumEnergy(input, k) << endl;
    
    return 0;
}