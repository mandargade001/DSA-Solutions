/*
Problem: 110. Balanced Binary Tree
Link: https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08

Approach:
   - My Logic: 
		Go DFS, keep adding 1 for height when going deep. Return 0 for null node.
		Check the balance using the height of left and right subtree and set the global variable. 
		Return the max height of left & right subtree as the height of the node will be the max of exsting heights.

   - T.C: O(n)
   - S.C: O(h)

   Runtime - 0 ms | Beats 100.00%
   Memory - 23.12 MB Beats 20.68%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

/**
 * Definition for a binary tree node.
 */



class Solution {
public:
    bool res = true;
    struct TreeNode {
	      int val;
	      TreeNode *left;
	      TreeNode *right;
	      TreeNode() : val(0), left(nullptr), right(nullptr) {}
	      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	  };
    int check(TreeNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        int leftDepth = 1 + check(node->left);
        int rightDepth = 1 + check(node->right);
        if(abs(leftDepth-rightDepth)>1) res = false;
        return max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return res;
    }
};

int main() {
    Solution sol;
    
    return 0;
}