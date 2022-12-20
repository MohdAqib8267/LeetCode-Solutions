class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int n){
        if(i==n){
            return 0;
        }
        if(j<0 or j>=n){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
             int ld=solve(i+1,j-1,matrix,dp,n);
              int d=solve(i+1,j,matrix,dp,n);
            int rd=solve(i+1,j+1,matrix,dp,n);
       dp[i][j]=matrix[i][j]+min({ld,d,rd});
        return dp[i][j];
       
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            int get_ans=solve(0,i,matrix,dp,n);
            ans=min(ans,get_ans);
        }
        return ans;
        
    }
};