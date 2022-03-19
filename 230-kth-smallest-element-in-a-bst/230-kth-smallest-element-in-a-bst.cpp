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
    vector<int> inorder; 
public:
    int kthSmallest(TreeNode* root, int k) {
        
        inorderTra(root);
        
        return inorder[k - 1];
    }
    
    void inorderTra(TreeNode* root){
        if(root->left) inorderTra(root->left);
        inorder.push_back(root->val);
        if(root->right) inorderTra(root->right);
    }
};