/*
Problem: 5. 3Sum
Link: https://leetcode.com/problems/3sum/description/

Approach:
   - My Logic: pre-requisite=2 Sum problem
   		Sort the array, to identify how to move in order to get desired sum.
   		Make use of 3 Pointers, for every element(1st pointer) [arr[i]]: 
   		divide the remaining array into 2 pointer solution for sum = 0 - arr[i].


   - T.C: O(N*logN)[sorting] + O(N^2)[2 pointer iteration]
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int target = -nums[i];
            int l = i+1;
            int r= nums.size()-1;
            while(l<r)
            {
                int sum = nums[l]+nums[r];
                if(sum>target)
                    r--;
                else if(sum<target)l++;
                else
                {
                    vector<int>triplet={nums[i],nums[l],nums[r]};
                    res.push_back(triplet);
                    while(l<r && triplet[1]==nums[l])l++;
                    while(l<r && nums[r]==triplet[2])r--;
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])i++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> res = sol.threeSum(input);

    for(const auto& row : res) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    
    return 0;
}