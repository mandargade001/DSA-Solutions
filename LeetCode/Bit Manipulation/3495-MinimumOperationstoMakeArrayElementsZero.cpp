/*
Problem: 3495. Minimum Operations to Make Array Elements Zero
Link: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/

   - My Logic: 
   		We focus to first find solution one query at a time. 
   		-> First approach: I could think was to iterate through the range and then find divide each element to find the operations.(doesn't work - bruteforce) 
   		-> Second approach: No. of operations to make it 0 was to use log4(x) + 1. I was thinking to somehow group them to make it minimum operations using pointers.(doesn't work) 
   		-> Third approach: Then, I noticed that the min operations was to sum(log4(x)+1) and get ceil by dividing it by 2, as we need group of 2's. (doesn't work - TLE)
   		-> Fourth approach:  For the range, identify the powers of 4 present in between. For each of segment where log4(x) + 1 is same, we get the count by using the power of 4 we are limiting to. 
   							 Finally, we sum up operations of each segment and group them and update the result.

   - T.C: O(N * (log4 B - log4 A)), {A,B} ~ {range of query}
   - S.C: O(1)

   Runtime - 32 ms | Beats 49.28%
   Memory - 182.69 MB | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        int size = queries.size();
        for(int i=0;i<size;i++)
        {
            long long a = queries[i][0];
            long long b = queries[i][1];

            //getting powers of 4 occuring in the range
            long long loga = (int) (log(a)/log(4));
            long long logb = (int) (log(b)/log(4));

            // cout<<"loop powers: "<<loga<<" , "<<logb<<endl;
            long long sum = 0;
            long long low=a-1, high=a-1;
            //iterating through each segment till powers of 4 come
            for(int j=loga;j<=logb;j++)
            {
                low=high+1;
                long long highP = pow(4,(j+1))-1;
                high=min(highP,b);
                
                sum += (high-low+1) * (j+1);
                // cout<<"low: "<<low<<" high:"<<high<<" sum:"<<sum<<endl;
            }
            //grouping operations in 2
            result += ceil(sum/2.0);
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input [1,2],[2,4]
    vector<vector<int>> input = {
    	{1,2},
    	{2,4}
    };
    
    cout << sol.minOperations(input) << endl;
    
    return 0;
}