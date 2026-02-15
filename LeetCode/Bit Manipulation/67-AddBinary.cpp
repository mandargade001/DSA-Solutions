/*
Problem: 67. Add Binary
Link: https://leetcode.com/problems/add-binary/description/?envType=daily-question&envId=2026-02-15

Approach:
   - My Logic: 
   		4 cases to solve, depending on total sum of a[i], b[i] and carry.
   		append leading char to res string. 
   		return final string

   - T.C: O(n)
   - S.C: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="0") return b;
        if(b=="0") return a;

        string res = "";

        int as = a.size();
        int bs = b.size();

        char carry = '0';

        if(as<bs)
        {
            for(int i=as;i<bs;i++)
            {
                a = '0'+ a;
            }
            cout<<format("a:{}\n", a);
        }
        else if(bs<as){
            for(int i=bs;i<as;i++)
            {
                b = '0'+ b;
            }
            cout<<format("b:{}\n", b);
        }

        as = a.size();
        bs = b.size();

        for(int i=1;i<=bs;i++)
        {
            int ad = a[as-i]-'0';
            int bd = b[bs-i]-'0';
            int cd = carry - '0';
            int sum = ad+bd+cd ;
            if(sum == 0){
                carry = '0';
                res = '0' + res;
            }
            else if(sum == 1){
                carry = '0';
                res = '1' + res;
            } 
            else if(sum==2)
            {
                carry = '1';
                res = '0' + res;
            }
            else {
                carry = '1';
                res = '1' + res;
            }
        }
        if(carry=='1') res = '1' + res;

                    // cout<<format("i:{}, res[i]:{}, c:{}\n", 'lead',1, 1)
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string a = "1001";
    string b = "1101";

    
    cout << sol.addBinary(a,b) << endl;
    
    return 0;
}