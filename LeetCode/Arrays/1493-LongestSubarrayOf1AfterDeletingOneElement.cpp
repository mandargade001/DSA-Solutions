/*
Problem: 1493 - Longest Subarray of 1's After Deleting One Element
Leetcode link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

Approach:
   - Logic: 
   		Skip initial 0's.
   		Variables to track sum, sum before including any 0, result.
   		Iterate the array and update result till at max one 0 is included.
   		If two 0's are found, reset by removing presum from sum.
   - T.C: O(N)
   - S.C: O(1)

   **NOTE: Sliding Window technique works here, just that first approach I could think was this.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    	int allowed=1, sum=0, presum=0, maxL=0;
        int it=0;
        while(it<nums.size() && nums[it]==0) it++;
        for(int i=it;i<(int)nums.size();i++)
        {
        	if(nums[i]==0 && nums[i-1]==0)
        	{
        		maxL=max(maxL,sum);
        		sum=0;
        		presum=0;
        		allowed=1;
        	}
        	if(nums[i])
        	{
        		sum++;
        		if(allowed) presum++;
        	}
        	else
        	{
        		if(allowed) allowed--;
        		else 
        		{
        			maxL=max(maxL,sum);
        			sum-=presum;
        			presum=sum;
        		}
        	}
        }
        maxL=max(maxL,sum);
        if(maxL==nums.size()) return maxL-1;
        return maxL;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,1,1,0,1,1,0,0,1};
    
    cout << sol.longestSubarray(input);
    
    return 0;
}