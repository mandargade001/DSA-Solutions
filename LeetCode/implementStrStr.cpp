#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    if(needle.size()==0)return 0;
    int h=haystack.length();
    int n=needle.length();
    int itr=0;
    int res=-1;
    bool flag=false;
    for(int i=0;i<h;i++)
    {
        if(haystack[i]==needle[itr])
        {
            res=i;
            flag=true;
            while(i<h && itr<n && haystack[i]==needle[itr])
            {
                i++;
                itr++;
            }
            if(itr<n)
            {
                flag=false;
                i=res;
                itr=0;
                continue;
            }
            if(flag)
            {
                return res;
            }   
        } 
    }
    return -1;
}

int main()
{
	string hay;
	string needle;
	cin>>hay>>needle;
	cout<<strStr(hay,needle)<<endl;
	return 0;
}
