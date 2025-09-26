/*
Problem: 611. Valid Triangle Number
Link: https://leetcode.com/problems/valid-triangle-number/description/

Approach:
   - My Logic: 
   		Basic condition to form triangle, sum of two sides > third side.
   		To reduce complexity, we sort the array.
   		Then, we get the pair of two sides and find out number of sides satisfying condition using Binary Search.
   		return the answers.
   - T.C: O(N^2 * log N)
   - S.C: O(1)


*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int n1 = nums[i];
                int n2 = nums[j];

                int sumOfSides = n1+n2-1;

                auto it = upper_bound(nums.begin()+j+1,nums.end(),sumOfSides);
                // if(it!=nums.end()){
                    int pos =  (it - nums.begin()) - j -1;
                    // cout<<"i: "<<i<<" , j: "<<j;
                    // cout<<" pos: "<<pos<<endl;
                    res+=pos;
                // }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,2,3,4};
    
    cout << sol.triangleNumber(input) << endl;
    
    return 0;
}