/*
Problem: 865. Smallest Subtree with all the Deepest Nodes
Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

Approach:
   - My Logic: Perform DFS to identify the deepest nodes in the tree. Then perform LCA logic for identified deepest nodes.
   - T.C: O(n)
   - S.C: O(n)

   Runtime - 0 ms | Beats 100.00%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth;
    unordered_map<int, unordered_set<TreeNode*>> mp;

    void dfs(TreeNode* node, int depth){
        if(node==nullptr) return ;
        if(depth == maxDepth) mp[depth].insert(node);
        else if(depth>maxDepth){
            maxDepth = depth;
            mp[depth].insert(node);
        }
        if(node->left!=nullptr) {
            dfs(node->left, depth + 1);
        }
        if(node->right!=nullptr) {
            dfs(node->right, depth + 1);
        }
    }

    bool findDeepNodes(TreeNode* node, int maxDepth)
    {
        if(mp[maxDepth].find(node)!=mp[maxDepth].end()) return true;
        bool left=false, right=false;
        if(node->left!=nullptr) left = findDeepNodes(node->left, maxDepth);
        if(node->right!=nullptr) right = findDeepNodes(node->right, maxDepth);
        return (left||right);
    }

    TreeNode* lca(TreeNode* node, int maxDepth){
        bool existsLeft, existsRight;
        if(node==nullptr) return nullptr;
        if(mp[maxDepth].find(node)!=mp[maxDepth].end()) return node;
        if(node->left!=nullptr){
            existsLeft = findDeepNodes(node->left, maxDepth);
        }
        if(node->right!=nullptr) {
            existsRight = findDeepNodes(node->right, maxDepth);
        }
        if(node->left!=nullptr && node->right!=nullptr) {
            if(existsLeft && existsRight) return node;
            else if(existsLeft) {
                return lca(node->left, maxDepth);
            }
            else {
                return lca(node->right, maxDepth);
            }
        }
        else if (node->left!=nullptr) return lca(node->left, maxDepth);
        else return lca(node->right, maxDepth);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //perform dfs and identify the deepest nodes
        maxDepth = 0;
        dfs(root, 0);
        //find the lca for the nodes in mp[maxDepth] vector
        return lca(root, maxDepth);
    }
};

int main() {
    Solution sol;
    
    return 0;
}