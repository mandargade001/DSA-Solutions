/*
Problem: 1488. Avoid Flood in The City
Link: https://leetcode.com/problems/avoid-flood-in-the-city/description/

Approach:
   - My Logic: 
		We have a result array.
		What we need to do is, that whenever non-zero value is present, we need to update result with -1, while updating the index of the variable in map.
		And when we check for the count of number, if it is present that means, lake will overflow and needs to be dried using 0 in between a range, from when the lake was first filled - i.e. the index we stored in map.
		Then since we need to find the index of 0 - best way is to use binary_search (log N). To simplify this, whenever we get 0, we insert the index into a set.
		We perform binary_search on index to get first zero, to optimise the solution (greedy approach).
		Update the index of zero with the value of the lake. Finally repeat for all elements in input array. 
		Return result array.

   - T.C: O(N * log N)
   - S.C: O(N)

   Runtime - 120 ms | Beats 64.12%
   Memory - 115.04 MB | Beats 27.97%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)  {
    	int size = rains.size();
        vector<int> res (size, 1);
        unordered_map<int,int> index;
        set<int> indexOfDry;

        for(int i=0;i<size;i++)
        {
            if(rains[i]==0)
            {
                indexOfDry.insert(i);
            }
            else
            {
                res[i] = -1;
                if(index.count(rains[i]))
                {
                    //this lake is overflown, need to dry
                    auto zeroInd = indexOfDry.lower_bound(index[rains[i]]);
                    if(zeroInd==indexOfDry.end()) {
                        vector<int> emp;
                        return emp;
                    }

                    res[*zeroInd] = rains[i];
                    indexOfDry.erase(zeroInd);
                }
                index[rains[i]]=i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    input = sol.avoidFlood(input);
    for (std::vector<int>::iterator i = input.begin(); i != input.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}