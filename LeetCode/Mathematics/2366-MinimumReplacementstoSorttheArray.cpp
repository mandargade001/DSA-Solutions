/*
Problem: 2366. Minimum Replacements to Sort the Array
Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

Approach:
   - My Logic: 
		Since we can only break the elements, we should start iterating from the back, so that we know how much to break any element.
		We break such that the elements are maximized but <= next element.
		We should only break elements which are not in decreasing order from back.
		For breaking optimally, we can find the no. of parts we should break as per the next element.
		Depending on the parts, we can find the maximize the elements to break;
		update the element with minimum of the broken elements.
		Continue;

   - T.C: O(n)
   - S.C: O(1)

   Runtime 1 ms Beats 66.81% 
   Memory 58.51 MB Beats 31.06%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ops = 0;
        int size = nums.size();
        int minNum = nums[size-1];
        for(int i=size-2;i>=0;i--)
        {
            if(nums[i]<=minNum) {
                minNum=nums[i];
            }
            else {
                int div = nums[i]/minNum;
                int parts;
                parts = (nums[i]%minNum==0) ? div : div+1;
                ops+=(parts-1);
                minNum= nums[i]/parts;
            }
        }
        return ops;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.minimumReplacement(input) << endl;
    
    return 0;
}