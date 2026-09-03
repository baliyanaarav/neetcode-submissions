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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                if(i==s-1){
                    ans.push_back(q.front()->val);
                }
               TreeNode* to=q.front();
               if(to->left)
               q.push(to->left);
               if(to->right)
               q.push(to->right);
                q.pop();
            }
        }
        return ans;
    }
};
