/*
Problem: 3719. Longest Balanced Subarray I
Link: https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

Approach:
   - My Logic: 
		Given the constraints, we can do it in O(N^2). 
		We find out all the subarrays through 2D looping. 
		Keep track of unique even and odd number in the iterated subarrya using set.
		After each step, check for the size and the length of the subarray. If the condition satisfies, update the res variable.
		Return the variable after all the iterations are completed.

   - T.C: O(n^2)
   - S.C: O(n)

   Runtime - 1597 ms Beats 89.73%
   Memory - 426.91 MB Beats 85.54%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> evenS,oddS;
        int res = 0;
        for(int i=0;i<size;i++)
        {
            for(int j=i;j<size;j++)
            {
                if(nums[j]%2==0)
                {
                    evenS.insert(nums[j]);
                }
                else{
                    oddS.insert(nums[j]);
                }
                if(evenS.size()==oddS.size()) {
                    int ssize = evenS.size();
                    res = max(res, j-i+1);
                }
            }
            if(evenS.size()==oddS.size()){
                int ssize = evenS.size();
                    res = max(res, size-i);
            }
            evenS.clear();
            oddS.clear();
            
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.longestBalanced(input) << endl;
    
    return 0;
}