#include<bits/stdc++.h>
using namespace std;

int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n=aliceValues.size();
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({abs(aliceValues[i]+bobValues[i]),i});
    }
    int aliceScore=0;
    int bobScore=0;
    int turn=0;
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        if(turn%2==0)
        {
            aliceScore+=aliceValues[p.second];
        }
        else {
            bobScore+=bobValues[p.second];
        }
        turn++;
    }
    if(aliceScore==bobScore)return 0;
    else 
    {
        return (aliceScore>bobScore?1:-1);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>a,b;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		a.push_back(num);
	}
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		b.push_back(num);
	}
	cout<<stoneGameVI(a,b)<<endl;
	return 0;
}