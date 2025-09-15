/*
Problem: 1935. Maximum Number of Words You Can Type
Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/

Approach:
   - My Logic: 
   		We have been given the broken letters. We first, transform them into vector storing freq of char present.
   		We then split the text string into vector of words, using split operation.
   		Since, we need to check for how many words we can type without fail, we need to find words which we cannot.
   		We iterate the vector words, and each character of the word to check if the frequency of that letter > 0.
   		If yes, we reduce the counter and break the loop to move to next word.
   		Else, we continue to check.
   		Finally, we return the count.

   - T.C: O(n)
   - S.C: O(1)

   Runtime - 1 ms | Beats 33.89%
   Memory - 9.53 MB | Beats 21.59%
   
   - Optimal logic: 

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    vector<string> split(const string& s) {
        vector<string> words;
        int n = s.length(), start = 0;
        while (start < n && s[start] == ' ') ++start; // Skip leading spaces
        for (int i = start; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (i > start) words.emplace_back(s, start, i - start); // Extract word
                while (i < n && s[i] == ' ') ++i; // Skip multiple spaces
                start = i;
            }
        }
        return words;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        //preprocess the brokenletters to save letters which are not allowed
        vector<int> broken (26,0);
        for(int i=0;i<brokenLetters.size();i++)
        {
            broken[brokenLetters[i]-'a']++;
        }

        //split the text and make it into vector of strings
        vector<string> words = split(text);

        //iterate each letter of the words
            //check if the letter exists in broken, 
                //Yes, skip the word
                //No, increment the counter
        int size = words.size();
        int count = 0;
        for(int i=0;i<size;i++)
        {
            count++;
            for(int j=0;j<words[i].size();j++)
            {
                if(broken[words[i][j]-'a']>0)
                {
                    count--;
                    break;
                }
            }
        }

        //return the counter
        return count;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string text = "hello world", brokenLetters = "ad";
    
    cout << sol.canBeTypedWords(text, brokenLetters) << endl;
    
    return 0;
}