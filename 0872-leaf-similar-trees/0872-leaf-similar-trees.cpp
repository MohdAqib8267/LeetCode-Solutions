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
    void preorder(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            ans.push_back(root->val);
            return;
        }
        preorder(root->left,ans);
        preorder(root->right,ans);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        vector<int>r2;
        preorder(root1,r1);
        preorder(root2,r2);
        if(r1.size()!=r2.size()){
            return false;
        }
        for(int i=0;i<r1.size();i++){
            if(r1[i]!=r2[i]){
                return false;
            }
        }
        return true;
    }
};