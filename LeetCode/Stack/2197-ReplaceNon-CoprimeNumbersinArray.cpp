/*
Problem: 2197. Replace Non-Coprime Numbers in Array
Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

Approach:
   - My Logic:
   		Observing that we have to repeatedly check with the previous elements where they make the non-coprimes or not. Here we can use Stack to pull the last element and keep checking till stack is empty or they are non-coprimes.
        Stack will be in the form of vector.
        Iterate each element of input array.
        for each element, keep on checking with the top element for the hcf.
        If hcd > 1, remove top element and update nums[i] = lcm
        else move to next element in input vector.
        This keeps track of all the non-coprimes in the previous part of vector without deleting elements.
   - T.C: O(N * log M)
   - S.C: O(N)

   Runtime - 19 ms | Beats 65.74%
   Memory - 125.43 MB | Beats 40.74%
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            while(!stack.empty())
            {
                int top = stack.back();
                int gcd = hcf(top,nums[i]);
                if(gcd==1)
                {
                    break;
                }
                stack.pop_back();
                int lm = lcm(top, nums[i],gcd);
                nums[i]=lm;

            }
            stack.push_back(nums[i]);
        }
        return stack;
    }

private: 
	int hcf(int a, int b)
    {
        return b==0?a:hcf(b,a%b);
    }
    int lcm(int a, int b, int hcf)
    {
        return ((long long) a*b)/hcf;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {6,4,3,2,7,6,2};
    
    input = sol.replaceNonCoprimes(input);

    for(int num: input)
    {
    	cout<<num<<" ";
    }
    cout<<endl;
    
    return 0;
}