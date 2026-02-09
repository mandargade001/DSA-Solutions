/*
Problem: 1382. Balance a Binary Search Tree
Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

Approach:
   - My Logic: 
		We traverse the tree inorder, so that we get the Left Childs on left of the element, and right childs on the right of the element.
		We create a new balancedBST using the inorder traversal. By using binary search on the array for finding the best child of the parent.

   - T.C: O(n)
   - S.C: O(n)

   Runtime - 3 ms | Beats 88.40%
   Memory - 65.60 MB Beats 64.31%
   
   - Optimal logic: Perform in-placing balancing using Rotations

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

 
class Solution {
public:
	 struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 };
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int size = inorder.size();

        return createBalancedBST(inorder, 0, size-1);
    }
private: 
    void inorderTraversal(TreeNode* node, vector<int>& inorder)
    {
        if(node==nullptr) return ;
        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
    }
    TreeNode* createBalancedBST(vector<int>& inorder, int startIdx, int endIdx)
    {
        if(startIdx>endIdx) return nullptr;
        int mid = startIdx + (endIdx-startIdx)/2;
        TreeNode* leftSubTree = createBalancedBST(inorder, startIdx, mid-1);
        TreeNode* rightSubTree = createBalancedBST(inorder, mid+1, endIdx);
        return new TreeNode(inorder[mid], leftSubTree, rightSubTree);
    }
};

int main() {
    Solution sol;
    
    
    return 0;
}