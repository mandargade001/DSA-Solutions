#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)return ;
        int l=0;int r=0;
        while(l<=r && r<nums.size())
        {
            if(nums[r]==0)
            {
                r++;
            }
            else
            {
                nums[l]=nums[r];
                r++;
                l++;
            }
        }
        while(l<nums.size())
        {
            nums[l]=0;
            l++;
        }
        
    }

int main()
{
	vector<int>nums;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		nums.push_back(a);
	}
	moveZeroes(nums);
	for(auto it:nums)
	{
		cout<<it<<" ";
	}
	return 0;
}