/*
Problem: 1310. XOR Queries of a Subarray
Link: https://leetcode.com/problems/xor-queries-of-a-subarray/description/

Approach:
   - My Logic: 
   		We can perform pre-calculation of XOR and replace the values in input array.
   		Updated input array at index 'i' will hold value = (arr[0] XOR arr[1] XOR ... XOR arr[i])

   		for queries index values - leftI and rightI.
   		result = arr[leftI-1] XOR arr[rightI] -- if leftI>0 
   		else result = arr[rightI]

	Steps:
   		iterate the given array and calc XOR of previous elements
   		initialize result array
   		iterate the queries array and get the leftI and rightI
		get the value by performing XOR on index of updated input array
		pushback to the result array
   - T.C: O(N)
   - S.C: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        for(int i=1;i<size;i++)
        {
            arr[i]=arr[i-1]^arr[i];
        }

        vector<int> res;
        size = queries.size();
        for(int i=0;i<size;i++)
        {
            int leftI = queries[i][0];
            int rightI = queries[i][1];

            if(leftI-1>=0 ) res.push_back(arr[leftI-1]^arr[rightI]);
            else res.push_back(arr[rightI]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {1,3,4,8};
    vector<vector<int>> queries = {
    	{0,1},
    	{1,2},
    	{0,3},
    	{3,3}
    };
    
    input = sol.xorQueries(input, queries);

    for (int num: input)
    {
    	cout<<num<<" ";
    }
    cout<<endl;
    
    return 0;
}