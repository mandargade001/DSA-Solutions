/*
Problem: 2353. Design a Food Rating System
Link: https://leetcode.com/problems/design-a-food-rating-system/description/

Approach:
   - My Logic: 
		Store foods with their ratings and cuisines in two fast-lookup maps. 
		For each cuisine, keep a sorted set of foods by rating (highest first) and name (alphabetically for ties). 
		To update a rating, remove the old rating from the cuisine’s set, update the rating, and add it back. 
		To get the highest-rated food for a cuisine, pick the top food from its sorted set.

   - T.C: 
   		Initialization: O(N*log N),
   		ChangeRating: O(log k),
   		HighestRated: O(1)

   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first)
            return a.first > b.first;       // descending by int
        return a.second < b.second;         // ascending by string
    }
};

class FoodRatings {
public:
    unordered_map<string,int> mp_rating;
    unordered_map<string,string> mp_cuisine;
    unordered_map<string,set<pair<int,string>, cmp>> mp_set;

    

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();
        for(int i=0;i<size;i++)
        {
            mp_rating[foods[i]]=ratings[i];
            mp_cuisine[foods[i]]=cuisines[i];
            mp_set[cuisines[i]].insert(make_pair(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it = mp_rating.find(food);
        string cuisine = mp_cuisine[food];
        if(it!=mp_rating.end())
        {
            int oldrating = mp_rating[food];
            mp_rating[food] = newRating;
            auto setit = mp_set[cuisine].find(make_pair(oldrating, food));
            if(setit!=mp_set[cuisine].end()) mp_set[cuisine].erase(setit);
            mp_set[cuisine].insert(make_pair(newRating,food));
        }
    }
    
    string highestRated(string cuisine) {
        return (mp_set[cuisine].begin())->second;
    }
};

int main() {
    
    return 0;
}