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
    void goodnode(TreeNode* root,int maxi,int &c){
        if(root==NULL)
        return;
        if(root->val>=maxi){
        c++;
        maxi=root->val;}
        goodnode(root->left,maxi,c);
        goodnode(root->right,maxi,c);

    }
    int goodNodes(TreeNode* root) {
        int c=0;
        goodnode(root,INT_MIN,c);
        return c;
    }
};
