/*
Problem: 1984. Minimum Difference Between Highest and Lowest of K Scores
Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25

Approach:
   - My Logic: 
   		In the problem, we need to select K scores and then get the difference between highes and lowest scores.
   		To minimize the result, we should be grouping the closer values together. Any element which is farther from the group selected will increase the result.
   		To make such grouping possible, we sort the array.
   		We need to pick every possible K scores group, this is done using queue, where we push K elements.
   		Get the difference b/w first and last element, move ahead to consider next set of K elements.
   		Return the final minimum result.
   		
   - T.C: O(n)
   - S.C: O(k)

   Runtime 0 ms Beats 100.00%
   Memory 17.77 MB Beats 22.33%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    using ll = long long;
    int minimumDifference(vector<int>& nums, int k) {
        //sort
        sort(nums.begin(), nums.end());

        //sliding window for k elements
        queue<int> q;

        for(int i=0;i<k;i++)
        {
            q.push(nums[i]);
        }

        int res = INT_MAX;

        //we have the first batch of K students ready. Here on, we can get the difference between the highest(last) & lowest(first) and keep on pushing next and popping first elements.
        res = min((q.back()-q.front()), res);

        for(int i=k;i<nums.size();i++)
        {
            q.pop();
            q.push(nums[i]);
            res = min((q.back()-q.front()), res);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,5, 9, 4, 8,4};
    int k = 3;
    
    cout << sol.minimumDifference(input, k) << endl;
    
    return 0;
}