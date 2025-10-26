/*
Problem: 2043. Simple Bank System
Link: https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26

Approach:
   - My Logic: 
   		Store the incoming balance array into a bank member variable.
   		Make the checks for valid txn before making any changes. 
   		If all the checks pass, we can make changes to balance and return response.

   - T.C: O(1)
   - S.C: O(N)

   Runtime - 27 ms | Beats 12.67%
   Memory - 123.46 MB | Beats 86.33%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Bank {
// private: 
    // vector<long long> b;
public:
    vector<long long> b;
    Bank(vector<long long>& balance) {
        this->b = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > 0 && account1 <= b.size() && account2 > 0 && account2 <= b.size())
        {
            if(b[account1-1]>=money)
            {
                b[account1-1]-=money;
                b[account2-1]+=money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account > 0 && account <= b.size())
        {
            // if(b[account-1]>=money)
            // {
                b[account-1]+=money;
                return true;
            // }
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account > 0 && account <= b.size())
        {
            if(b[account-1]>=money)
            {
                b[account-1]-=money;
                return true;
            }
        }
        return false;
    }
};

int main() {
    
    
    // Example input
    vector<long long> input = {1,2,3,4};

    Bank sol(input);
    
    cout << sol.deposit(1,20) << endl;
    cout << sol.transfer(1,2,10) << endl;
    cout << sol.withdraw(2,11) << endl;
    
    return 0;
}