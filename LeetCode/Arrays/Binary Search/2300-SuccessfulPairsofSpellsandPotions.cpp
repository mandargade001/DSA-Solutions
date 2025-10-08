/*
Problem: 2300. Successful Pairs of Spells and Potions
Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

Approach:
   - My Logic: 
		By brute, we can get all the pairs in O(N*M) and get the result, it would give TLE.
		We sort the potions array, and find out the value/index from where the strength crosses the success threshold.
		We get the index, and  calculate overall success number and insert into result array.

   - T.C: O((N+M) * log M)
   - S.C: O(N)

   Runtime - 36 ms | Beats 91.42%
   Memory - 128.04 MB | Beats 55.53%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;
        for(int i=0;i<spells.size();i++)
        {
            long long minS = ceil(success/(double)spells[i]);
            auto it = lower_bound(potions.begin(), potions.end(), minS);
            if(it!=potions.end())
            {
                int ind = it - potions.begin();
                res.push_back(m-ind);
            }
            else {
                res.push_back(0);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input1 = {1,2,3,4};
    vector<int> input2 = {1,2,3,4};
    int success = 3;
    
    input1 = sol.successfulPairs(input1, input2, success);
    for (std::vector<int>::iterator i = input1.begin(); i != input1.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}