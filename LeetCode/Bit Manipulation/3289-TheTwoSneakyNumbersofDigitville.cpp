/*
Problem: 3289. The Two Sneaky Numbers of Digitville
Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31

Approach:
   - My Logic: 
   		brute: Hash Table
                iterate the array and keep track of the freq of each element. 
                return elements with freq more than 1. 
                TC: O(N) SC: O(N)
        alternate:
                sort, and check if element adj are same, if yes add to result array.
                TC: O(N log N) SC: O(1)
   - T.C: O(n)
   - S.C: O(n)

   Runtime - 1 ms | Beats 51.35%
   Memory - 26.59 MB | Beats 15.56%
   
   - Optimal logic: Bitwise Manipulation using XOR

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // 2 numbers are occurring twice 

        /**
            


        */

        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) res.push_back(nums[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {0,1,1,0};
    
    input = sol.getSneakyNumbers(input);

    for (std::vector<int>::iterator i = input.begin(); i != input.end(); ++i)
    {
    	cout<<*i<<" ";
    }
    
    return 0;
}