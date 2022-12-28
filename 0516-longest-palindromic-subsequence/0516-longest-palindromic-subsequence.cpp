class Solution {
public:
    int LPS(int i,int j,int n,string &s,vector<vector<int>>& dp){
        if(i>=n or j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            dp[i][j]=1+LPS(i+1,j-1,n,s,dp);
        }
        else{
            dp[i][j]=max(LPS(i+1,j,n,s,dp),LPS(i,j-1,n,s,dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return LPS(0,n-1,n,s,dp);
        //Tabulation
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};