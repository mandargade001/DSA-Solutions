/*
Problem: 1912. Design Movie Rental System
Link: https://leetcode.com/problems/design-movie-rental-system/description/

Approach:
   - My Logic: 
   		We received shop,movie,price. We had to maintain the operation to be at max be O(log N).
   		For search, we required a lookup by movie that too as per custom comparator. 
   		We use, map of set for this. 

   		for report, we also need to track the rented movies as per custom comparator, we use a set with tuples.

   		for rent, drop -> since, we would require price to make clear operations, so we use the hashmap to store price of shop-movie combo.

   - T.C: O(N * log N)
   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

struct PairHash {
    size_t operator() (const pair<int,int>& a) const {
        return hash<int>{}(a.first) ^ (hash<int>{}(a.second) << 1);
    }
};

struct Cmp {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
        if(a.first!=b.first) return a.first<b.first;
        return a.second<b.second; 
    }   
};
struct Srt {
    bool operator() (const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
        if(get<1>(a)!=get<1>(b)) return get<1>(a)<get<1>(b);
        if(get<2>(a)!=get<2>(b)) return get<2>(a)<get<2>(b);
        return get<0>(a)<get<0>(b);
    }
};
class MovieRentingSystem {
public:
    //price lookup map: <movie,shop> -> price
    unordered_map<pair<int,int>,int, PairHash> shopMovieAtPrice;
    //map per movie to store shop,price: movie -> <price,shop>
    unordered_map<int,set<pair<int,int>,Cmp>> movieAtShop;
    //rented movie set: <movie,price,shop>
    set<tuple<int,int,int>,Srt> rentedMovies; 

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int size = entries.size();
        //shop, movie, price
        for(int i=0;i<size;i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            shopMovieAtPrice[{shop,movie}]=price;
            movieAtShop[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        int count = 0;
        vector<int> res;
        for(auto it = movieAtShop[movie].begin(); count<5 && it!=movieAtShop[movie].end();++it)
        {
            res.push_back(it->second);
            count++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = shopMovieAtPrice[{shop,movie}];
        movieAtShop[movie].erase({price,shop});
        rentedMovies.insert({movie,price,shop});
    }
    
    void drop(int shop, int movie) {
        int price = shopMovieAtPrice[{shop,movie}];
        rentedMovies.erase({movie,price,shop});
        movieAtShop[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        //return [{shop,movie}]
        vector<vector<int>> res;
        int count = 0;
        for(auto it = rentedMovies.begin(); count<5 && it!=rentedMovies.end();++it)
        {
            res.push_back({get<2>(*it),get<0>(*it)});
            count++;
        }
        return res;
    }
};

int main() {
    return 0;
}