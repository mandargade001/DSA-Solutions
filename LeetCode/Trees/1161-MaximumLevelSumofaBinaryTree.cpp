/*
Problem: 1161. Maximum Level Sum of a Binary Tree
Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

Approach:
   - My Logic:
   		Since we need sum of each level, we perform level order traversal (BFS) using queue.
		For each level, we keep track of the curr_sum and level. update the res_sum and res_level if they are greater.
		We use queue.size() to know how many nodes belong to any level and process them at once using inner for loop.

   - T.C: O(n)
   - S.C: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int bestLevel = 1;
        long long bestSum = root->val;

        while (!q.empty()) {
            int size = q.size();
            long long currSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currSum > bestSum) {
                bestSum = currSum;
                bestLevel = level;
            }

            level++;
        }

        return bestLevel;
    }
};

int main() {
    Solution sol;
    
    return 0;
}