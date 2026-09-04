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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        stack<TreeNode*>st;
        while(true){
             while(curr){
                st.push(curr);
                curr=curr->left;
             }
             TreeNode* to=st.top();
             curr=to->right;
             st.pop();
             k--;
             if(k==0)
             return to->val;
        }
        return -1;
    }
};
