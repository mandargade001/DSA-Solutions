/*
Problem: 3021. Alice and Bob Playing Flower Game
Link: https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/

Approach:
   - My Logic: 
   		According to the conditions given for alice to win the game, Alice has to be the last to pick a flower.
		Which means the sum of x & y in (x,y) should be always odd.
		We calculate the possible combinations by first getting the even and odd numbers in both rows.
		then use the formula (N_even * M_odd) + (N_odd * M_even).
		This gives all the possible combinations.
   - T.C: O(1)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long neven,nodd,meven,modd;
        if(n%2==0)
        {
            neven=n/2;
            nodd=neven;
        }
        else 
        {
            nodd=(n+1)/2;
            neven=nodd-1;
        }
        if(m%2==0)
        {
            meven=m/2;
            modd=meven;
        }
        else 
        {
            modd=(m+1)/2;
            meven=modd-1;
        }

        long long res = nodd*meven + modd*neven;
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int n=3, m=2;
    
    cout << sol.flowerGame(n,m) << endl;
    
    return 0;
}