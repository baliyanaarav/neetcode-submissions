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
        stack<TreeNode*>st;
        TreeNode* cur=root;
        while(true){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            TreeNode* to=st.top();
            st.pop();
            k--;
            if(k==0)
            return to->val;
            cur=to->right;
        }
        return -1;
    }
};
