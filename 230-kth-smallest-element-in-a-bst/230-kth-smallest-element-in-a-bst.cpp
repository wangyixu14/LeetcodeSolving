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
        dfs(root, k);
        return ans;
    }
    
    void dfs(TreeNode* root, int& cnt){
        if(!root) return;
        dfs(root->left, cnt);
        cnt--;
        if(cnt==0){
            ans = root->val;
            return;
        }
        dfs(root->right, cnt);
    }
    
};