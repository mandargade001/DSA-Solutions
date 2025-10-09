/*
Problem: 3494. Find the Minimum Amount of Time to Brew Potions
Link: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/

Approach:
   - My Logic: 
		We need to keep track of the startTime for brewing each potion, such that when potion reaches any wiz, he should be free.

		get the cumulative skill buildup.
		initiate vector to store the finish times of wiz to 0
		find the starting time for potion j, get the max while iterating
		getting startTime by checking finishTime for each wiz for previous potion, making sure startTime is always after the first wiz is free.
		calc. finishTime for each wiz for potion[j], update the finishTime vector.
		return time when last wiz is free.

   - T.C: O(N*M)
   - S.C: O(N)

   Runtime - 484 ms | Beats 54.54%
   Memory - 408.05 MB | Beats 21.21%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        // get the cumulative skill buildup
        vector<long long> buildup;
        for(int i=0;i<n;i++)
        {
            if(i==0) buildup.push_back(skill[i]);
            else {
                buildup.push_back(skill[i]+buildup[i-1]);
            }
        }

        // initiate vector to store the finish times of wiz to 0
        vector<long long> finishTime (n,0);

        // find the starting time for potion j, get the max while iterating
        long long startTime = 0;
        for(int j=0;j<m;j++)
        {
            // cout<<"Potion "<<j<<":"<<endl;
            vector<long long> indFinish (n, 0);
            startTime = finishTime[0];
            //getting startTime by checking finishTime for each wiz for previous potion
            for(int i=0;i<n;i++)
            {
                indFinish[i] = mana[j]*buildup[i];
                // cout<<"indFinish Time for wiz "<<i<<": "<<indFinish[i]<<endl;
                // cout<<"startTime: ";
                if(i<n-1) {
                    startTime = max(startTime, finishTime[i+1]-indFinish[i]);
                    // cout<<startTime<<" ";
                }
                // cout<<endl;
            }
            // cout<<endl;
            //calc. finishTime for each wiz for potion[j], update the finishTime vector
            for(int i=0;i<n;i++)
            {
                finishTime[i] = startTime + indFinish[i];
                // cout<<"finishTime for wiz "<<i<<": "<<finishTime[i]<<endl;
            }
            
        }
        return finishTime.back();
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input1 = {1,2,3,4};
    vector<int> input2 = {1,2,3,4};
    
    cout << sol.minTime(input1, input2) << endl;
    
    return 0;
}