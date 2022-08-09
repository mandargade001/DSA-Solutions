#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod=1e9+7;
void findFactors(int i,vector<int>&arr,vector<ll>&trees)
{
	unordered_map<int ,int>mp;
	ll count=1;
	for(int j=0;j<i;j++)
	{   if(mp.find(arr[j])!=mp.end())continue;
	    int factor1,factor2;
	    if(arr[i]%arr[j]==0)
	    {
	        
	        factor1=arr[j];
	        factor2=arr[i]/factor1;
	        mp[factor1]=1;
	        mp[factor2]=1;
	        int ind1=find(arr.begin(),arr.end(),factor1)-arr.begin(); 
	        int ind2=find(arr.begin(),arr.end(),factor2)-arr.begin();
	        if(ind1<arr.size() && ind2<arr.size())
	        {
	            if(factor1==factor2)
	            {
	                count=((count%mod)+(((trees[ind1]%mod)*(trees[ind2]%mod))%mod)%mod);
	            }
	            else
	            {
	                count=((count%mod)+ ( ( ( 2 * ( ( trees[ind1]%mod ) * ( trees[ind2]%mod ) )%mod )%mod )%mod)%mod);
	                // count=(count%mod)+((2*(trees[ind1]%mod)*(trees[ind2]%mod))%mod);
	                
	            }
	        }
	    }
	}
	trees[i]=(count%mod);
	return ;
}
int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<ll>trees(arr.size(),-1);
    for(int i=0;i<arr.size();i++)
    {
        findFactors(i,arr,trees);
    }
    ll sum=0;
    for(int it:trees)
        sum=((sum%mod)+(it%mod))%mod;
    return sum%mod;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	cout<<numFactoredBinaryTrees(v)<<endl;
	return 0;
}