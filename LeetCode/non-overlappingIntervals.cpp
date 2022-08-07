#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size()<=1)return 0;
    sort(intervals.begin(),intervals.end(),comp);
    int count=-1;
    vector<int>pre=intervals[0];
    for(auto it:intervals)
    {
        if(pre[1]>it[0])
        {
            count++;
        }
        else
        {
            pre=it;
        }
    }
    return count;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>>intervals(n,vector<int>(2));
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		intervals[i][0]=a;
		intervals[i][1]=b;
	}
	cout<<eraseOverlapIntervals(intervals)<<endl;
	return 0;
}