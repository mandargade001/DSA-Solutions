#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    sort(begin(nums),end(nums));
    int num=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=num)
        {
            return num;
        }
        else
        {
            num++;
        }
    }
    return nums.size();
}

int main()
{
	//Give input vector such that
	//size of vector = n & it contains elements from [0,n] with one number missing.
	int n;
	cin>>n;
	vector<int>nums;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		nums.push_back(a);
	}
	cout<<missingNumber(nums)<<endl;
	return 0;
}