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
    bool checkSym(TreeNode* l, TreeNode* r)
    {
        if(l==NULL && r==NULL)return true;
        if((l==NULL && r!=NULL)||(l!=NULL && r==NULL))return false;
        if(l->val!=r->val)return false;
        if((l->left && !r->right)||(!l->left && r->right)||(l->right && !r->left)||(!l->right && r->left))return false;
      
        return (checkSym(l->left,r->right)&&(checkSym(l->right,r->left)));
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        
        return checkSym(root->left,root->right);
        
    }
};