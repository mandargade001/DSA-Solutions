/*
Problem: 18. 4Sum
Link: http://leetcode.com/problems/4sum/description/

Approach:
   - My Logic: 
        we will sort the entire array in the first step and to get the unique quads, we will simply skip the duplicate numbers while moving the pointers.
        As the entire array is sorted, the duplicate numbers will be in consecutive places. So, while moving a pointer, we will check the current element and the adjacent element. Until they become different, we will move the pointer by 1 place. We will follow this process for all 4 pointers. Thus, we can easily skip the duplicate elements while moving the pointers.
        Among the 4 pointers, 2 will be fixed and 2 will be moving. In each iteration, we will check if the sum i.e. nums[i]+nums[j]+nums[k]+nums[l] is equal to the target. 

            If the sum is greater, then we need lesser elements and so we will decrease the value of l. 
            If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
            If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements.
   
   - T.C: O(N^3)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size=nums.size();
        int i=0;
        long long sum=0;

        sort(nums.begin(),nums.end());

        while(i<size-3)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                sum=nums[i];
                int j=i+1;
                while(j<size-2)
                {
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1]))
                    {
                        long long sum2=sum+nums[j];
                        int k=j+1,l=size-1;
                        long long rem=target-sum2;
                        while(k<l && k<size && l>1)
                        {
                            long long sum3=nums[k]+nums[l];
                            if(sum3==rem)
                            {
                                res.push_back({nums[i],nums[j],nums[k],nums[l]});
                                k++;l--;
                                while(k>0 && k<size && nums[k]==nums[k-1]) k++;
                                while(l<size-1 && l>1 && nums[l]==nums[l+1]) l--;
                            }
                            else if(sum3<rem) k++;
                            else if(sum3>rem) l--;
                        }
                    }
                    j++;
                }
            }
            i++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {-2,-1,-1,1,1,2,2};
    int target = 0;
    
    vector<vector<int>> res = sol.fourSum(input, target);

    for(const auto& row : res) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}