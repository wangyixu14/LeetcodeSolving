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
    TreeNode* top, *bot, *prev;
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        cout << top->val << bot->val;
        swap(top->val, bot->val);
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(prev and root->val < prev->val){
            if(!top) top = prev;
            bot = root;
        }
        prev = root;        
        dfs(root->right);
    }
};