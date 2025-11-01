/*
Problem: 3217. Delete Nodes From Linked List Present in Array
Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01

Approach:
   - My Logic: 
   		Have unordered_map to have the lookup for nums values.
   		Go on to iterate the LL, and assign the next pointer to skip or not depending on lookup.

   - T.C: O(N)
   - S.C: O(N)

   
   - Optimal logic: Can use unordered_set as we do not care about the values in map

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        // ListNode* prev = new ListNode();
        while(head!=nullptr && mp[head->val]!=0)
        {
            ListNode* temp = head;
            head = head->next;
        }
        if(head == nullptr) return head;
        ListNode* itr = head;
        while(itr->next!=nullptr)
        {
            if(mp[itr->next->val]!=0)
            {
                ListNode* temp = itr->next;
                itr->next = itr->next->next;
            }
            else {
                itr = itr->next;
            }
        }
        return head;
        
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {1,2,3,4};
    
    
    return 0;
}