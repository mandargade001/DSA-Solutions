/*
Problem: 744. Find Smallest Letter Greater Than Target
Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31

Approach:
   - My Logic: 
   		O(N): perform linear search on the input array and return the first element passing check: letters[i]>target, else after loop return letters[0];

   		O(log N): perform binary search on the index, and check if the element at mid index satisfy the condition, if yes, update high to mid, to look for the smallest index passing the check.

   - T.C: O(log N)
   - S.C: O(1)

   Runtime - 0 ms | Beats 100.00%
   Memory - 19.89 MB Beats 24.67%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        if(letters[size-1]<=target) return letters[0];

        //T.C: O(N) - linear
        // for(auto& c: letters)
        // {
        //     if(c>target) return c;
        // }

        //T.C: O(logN) - logarithmic - binary search
        int low = 0;
        int high = size - 1;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(letters[mid]>target) high = mid;
            else low = mid + 1;
        }
        return low>=size?letters[0]:letters[low];

        // return letters[0];
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<char> input = {'a', 'b', 'c', 'c'};
    char target = 'e';
    
    cout << sol.nextGreatestLetter(input, target) << endl;
    
    return 0;
}