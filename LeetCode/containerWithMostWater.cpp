#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int l=0;
    int r=n-1;
    int vol=INT_MIN;
    while(l<r && r<n)
    {
        int minH=min(height[l],height[r]);
        int len=r-l;
        vol=max(vol,minH*len);
        if(height[l]<height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return vol;
}

int main()
{
	int n;
	cin>>n;
	vector<int>h;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		h.push_back(a);
	}
	cout<<maxArea(h)<<endl;
	return 0;
}