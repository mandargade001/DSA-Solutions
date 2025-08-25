/*
Problem: 560 - Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/

Approach:
   - My Logic: 
   		First approach that striked me was using 'Sliding Window'. 
   		But that cannot be used as negative numbers are possible. We will miss out of some possible cases.

   		We can have a prefix_sum calculated and stored for future references.

   		Iterate the array by calculating its cumulative sum. Keep storing their frequencies in a MAP.
   		for every iteration, 
   			check if cumulative_sum==k
   			or if there exists a sub-array that we can remove to get sum=k
   		and finally, we update the map by current cumulative sum.

   - T.C: O(N)
   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int,int> mp;
    	int cum_sum=0, count=0;

    	for(int i=0;i<(int)nums.size();i++)
    	{
    		cum_sum+=nums[i];

    		if(cum_sum==k) count++;

    		int rem=cum_sum-k;

    		if(mp.find(rem)!=mp.end()) count+=mp[rem];

    		mp[cum_sum]++;
    	}

    	return count;
        
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,-4,-2,6,2,1,-2,-1};
    int k=3;
    // Ans = 6
    
    cout << sol.subarraySum(input,k) << endl;
    
    return 0;
}