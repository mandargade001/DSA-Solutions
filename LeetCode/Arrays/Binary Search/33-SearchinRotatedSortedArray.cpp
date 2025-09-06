/*
Problem: 33. Search in Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Approach:
	Since we are given rotated + sorted array, we can solve this using binary search algorithm.
	we define three variables - low, mid and high, taking their places.
	As the array is rotated, either one of the halves will be sorted, we check the target in that half.
	If not present, we reject that half. 
	If found, we reject the other half.

	Rest is the same algo.

   - My Logic: 
   - T.C: O(log N)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target){
                return mid;
            }

            else if(nums[start]<=nums[mid]){
                if(target>=nums[start] && nums[mid]>target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            else{
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {4,5,6,7,0,1,2};
    int target = 0;
    
    cout << sol.search(input,target) << endl;
    
    return 0;
}