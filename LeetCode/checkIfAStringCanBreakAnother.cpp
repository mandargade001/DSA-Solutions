#include<bits/stdc++.h>
using namespace std;

bool checkIfCanBreak(string s1, string s2) {
        
    int n=s1.length();
    
    sort(begin(s1),end(s1));
    sort(begin(s2),end(s2));
    
    bool flag2=true;
    bool flag1=true;
    
    for(int i=n-1;i>=0 &&(flag1 || flag2);i--)
    {
        if(s2[i]<s1[i])
        {
            flag2=false;
        }
        if(s1[i]<s2[i])
        {
            flag1=false;
        }
    }
    return (flag1 || flag2);
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<checkIfCanBreak(s1,s2)<<endl;
	return 0;
}