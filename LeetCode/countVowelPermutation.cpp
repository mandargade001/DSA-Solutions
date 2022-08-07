#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int dp[5][20000];

/*
   a -> 0
   e->  1
   i -> 2
   o -> 3
   u -> 4
 */  
int func(int i,int n,int x){
    if(x==n)
        return 1;
    if(dp[i][x]!=-1)
        return dp[i][x];
    
    int tot=0;
    if(i==0)
        tot=(tot+func(1,n,x+1))%mod;
    else if(i==1)
        tot=(tot+func(0,n,x+1)+func(2,n,x+1))%mod;
    else if(i==2){
        for(int j=0;j<5;j++){
            if(j!=2)
                tot=(tot+func(j,n,x+1))%mod;
        }
    }
    else if(i==3)
        tot=(tot+func(2,n,x+1)+func(4,n,x+1))%mod;
    else 
        tot=(tot+func(0,n,x+1))%mod;
    
    return dp[i][x]=tot;
}
int countVowelPermutation(int n) {
    memset(dp,-1,sizeof(dp));
    int tot=0;
    for(int i=0;i<5;i++)
        tot=(tot+func(i,n,1))%mod;
    return tot;
}

int main()
{
	int n;
	cin>>n;
	cout<<countVowelPermutation(n)<<endl;
	return 0;
}