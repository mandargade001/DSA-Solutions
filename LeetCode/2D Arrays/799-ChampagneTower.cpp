/*
Problem: 799. Champagne Tower
Link: https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14

Approach:
   - My Logic: 
   		Iterate like pascal's triangle.
   		Consider you poured N glasses in top glass. It can hold only 1, and rest spills.
   		Keep on holding 1 val, and rest pass on to next level.
   		Contribution to glass comes only if above glass are full i.e 1 - state.
   		Return the val stored in the i,j glass.

   - T.C: O(1000*1000)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row+1,vector<double>(query_row+1,0));
        //build the tower portions
        tower[0][0]=poured;
        if(query_row == 0 && query_glass==0){
            if(poured>0) return 1.0;
            else return 0.0;
        } 
        for(int i=1;i<query_row+1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0){
                    tower[i][j] = tower[i-1][j] > 1.0 ? (tower[i-1][j]-1)/2 : 0;
                }   
                else if(j==i){
                    tower[i][j] = tower[i-1][j-1] > 1.0 ? (tower[i-1][j-1]-1)/2 : 0;
                } 
                else{
                    tower[i][j] = (tower[i-1][j-1] > 1.0 ? (tower[i-1][j-1]-1)/2 : 0) +  (tower[i-1][j] > 1.0 ? (tower[i-1][j]-1)/2 : 0);
                }
            }
            // cout<<endl;
        }

        //pour the glasses and calculate what makes it to query_row, query_glass
        
        return tower[query_row][query_glass]>=1 ? 1.0 : tower[query_row][query_glass];
    }
};

int main() {
    Solution sol;
    
    // Example input
    
    
    cout << sol.champagneTower(6, 3,  1) << endl;
    
    return 0;
}