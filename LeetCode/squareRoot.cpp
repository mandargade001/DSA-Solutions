#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if(x==1)return 1;
    if(x==0)return 0;
    
    int l=1;
    int r=x/2;
    while(l<r && r<=x/2)
    {
        int mid=l+(r-l)/2;
        if((long long)mid*mid==(long long)x)return mid;
        else if((long long)mid*mid>(long long)x)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if((long long)r*r>(long long)x)return r-1;
    else
        return r;
}

int main()
{
	int n;
	cin>>n;
	cout<<mySqrt(n)<<endl;	
	return 0;
}
