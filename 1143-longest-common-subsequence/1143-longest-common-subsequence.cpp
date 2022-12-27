class Solution {
public:
    int LCS(int i,int j,string &s1,string &s2,int n,int m,vector<vector<int>>& dp){
        if(i>=n || j>=m)
            return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            dp[i][j] = 1 + LCS(i+1,j+1,s1,s2,n,m,dp);
        }
        else{
            dp[i][j] = max(LCS(i+1,j,s1,s2,n,m,dp),LCS(i,j+1,s1,s2,n,m,dp));
        }
        
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return LCS(0,0,text1,text2,n,m,dp);
    }
};