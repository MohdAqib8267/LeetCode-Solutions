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
    int MOD = 1e9 + 7;
    int nodesSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left=nodesSum(root->left);
        int right=nodesSum(root->right);
        return root->val+left+right;
        
    }
    long long DFS(TreeNode* root,int sum,long long &totalSumHere,long long &ans){
        if(root==NULL){
            return 0;
        }
        int l=DFS(root->left,sum,totalSumHere,ans);
        int r=DFS(root->right,sum,totalSumHere,ans);
        totalSumHere=l+root->val+r;
        ans=max(ans,(sum-totalSumHere)*totalSumHere);
        return totalSumHere;
        
    }
    int maxProduct(TreeNode* root) {
        int sum=nodesSum(root);
        
        //DFS- 
        long long totalSumHere=0;
        long long ans=0;
         DFS(root,sum,totalSumHere,ans);
        return ans%MOD;
        
    }
};