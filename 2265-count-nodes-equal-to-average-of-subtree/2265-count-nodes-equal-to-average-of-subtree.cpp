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
    int res = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    
    pair<int, int> dfs(TreeNode* root){
        if(!root) {
            return pair<int, int>{0, 0};
        }
        pair<int, int> left, right;
        left = dfs(root->left);
        right = dfs(root->right);
        if((left.first + right.first + root->val)/(left.second + right.second + 1) == root->val) res++;
        return pair<int, int>{left.first + right.first + root->val, left.second + right.second + 1};
    }
};