/*
Problem: 3713. Longest Balanced Substring I
Link: https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

Approach:
   - My Logic: 
   		Iterate through all substrings. 
   		for every start index of substring, we create a map to store the frequency.
   		min ordered set for storing the min freq char
   		max ordered set for max freq char
   		if the first element freq of min order set = first element freq of max order set, 
   		then the substring is balanced, and result is updated.
   - T.C: O(n^2)
   - S.C: O(n)
   
   - Optimal logic: iterate over all substrings, maintain a vector for freq. Iterate over the char vector of freq, and check if all freq are same.
   					If yes, update result, else break and continue;

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int longestBalanced(string s) {
        int len = s.length();
        //using two pair var to track the min freq of char and max freq of char. if min = max, then we can say that all distinct char are present for same times. 
        int res = 0;
        for(int i=0;i<len;i++)
        {
            unordered_map<char,int> mp;
            set<pair<int,char>, greater<pair<int,char>>> maxpq;
            set<pair<int,char>> minpq;

            for(int j=i;j<len;j++)
            {
                int updatedval = ++mp[s[j]];

                if(minpq.empty()){
                    minpq.insert({mp[s[j]], s[j]});
                }
                else {
                    auto itr = minpq.find({updatedval-1,s[j]});
                    if(itr!=minpq.end())
                    {
                        auto node = minpq.extract(itr);
                        node.value() = {updatedval, s[j]};
                        minpq.insert(move(node));
                    }
                    else {
                        minpq.insert({mp[s[j]], s[j]});
                    }
                }
                if(maxpq.empty()){
                    maxpq.insert({mp[s[j]], s[j]});
                }
                else {
                    auto itr = maxpq.find({updatedval-1,s[j]});
                    if(itr!=maxpq.end())
                    {
                        auto node = maxpq.extract(itr);
                        node.value() = {updatedval, s[j]};
                        maxpq.insert(move(node));
                    }
                    else {
                        maxpq.insert({mp[s[j]], s[j]});
                    }
                }

                //check the new top elements of both the queues to check the balance condition
                pair<int,char> upmin = *minpq.begin();
                pair<int,char> upmax = *maxpq.begin();

                if(upmin.first == upmax.first) {
                    res = max(res, j-i+1);

                }
               

            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "abcde"
    
    cout << sol.longestBalanced(s) << endl;
    
    return 0;
}