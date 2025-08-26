/*
Problem: 229. Majority Element II
Link: https://leetcode.com/problems/majority-element-ii/description/

Approach:
   - My Logic: 
   		Sort the array, and then iterate to track elements with count>N/3
   - T.C: O(N*logN) 
   - S.C: O(1)

   - Optimal logic: (Extended Moore's Voting Algorithm) 
		Keep track of count of two variables, keeping in mind that these 2 element do not coincide.
		If element other than these 2 comes, we decrease the count for both elements, else we increment the count.
   - T.C: O(2*N)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size=nums.size();
        int count=0, ele=nums[0];
        vector<int> res;
        for(int i=0;i<size;i++)
        {
        	if(nums[i]==ele) count++;
        	else 
        	{
        		if(count>size/3) res.push_back(ele);
        		ele=nums[i];
        		count=1;
        	}

        }
        if(count>size/3 )
        {
            if(res.size()>0 && res.back()!=ele) res.push_back(ele);
        	else res.push_back(ele);
        }
        return res;
    }

    vector<int> majorityElementOptimal(vector<int>& nums) {
        vector<int> res;
        int cnt1=0, ele1=INT_MIN;
        int cnt2=0, ele2=INT_MIN;
        int size=nums.size();

        for(int i=0;i<size;i++)
        {
        	if(cnt1==0 && ele2!=nums[i])
        	{
        		cnt1++;
        		ele1=nums[i];
        	}
        	else if(cnt2==0 && ele1!=nums[i])
        	{
        		cnt2++;
        		ele2=nums[i];
        	}
        	else if(cnt1>0 && nums[i]==ele1) cnt1++;
        	else if(cnt2>0 && nums[i]==ele2) cnt2++;
        	else {
        		cnt1--;
        		cnt2--;
        	}
        }
        int freq1=0, freq2=0;
        for(int i=0;i<size;i++)
        {		
        	if(nums[i]==ele1) freq1++;
        	if(nums[i]==ele2) freq2++;
        }
        if(freq1>size/3) res.push_back(ele1);
        if(freq2>size/3) res.push_back(ele2);
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {3,2,1,3,2,3};
    
    input=sol.majorityElementOptimal(input);

    for(int num: input) cout<<num<<" ";

    cout<<endl;
    
    return 0;
}