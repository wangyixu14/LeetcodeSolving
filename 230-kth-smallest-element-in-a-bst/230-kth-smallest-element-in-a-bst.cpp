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
private:
    int ans; 
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
    
    void helper(TreeNode* root, int &cnt){
        if(root->left) helper(root->left, cnt);
        cnt--;
        if(!cnt) {
            ans = root->val;
            return;
        }
        if(root->right) helper(root->right, cnt);
    }
};