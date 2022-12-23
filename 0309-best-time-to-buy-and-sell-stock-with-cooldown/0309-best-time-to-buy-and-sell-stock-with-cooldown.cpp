class Solution {
public:
    int solve(vector<int>& prices,int i,int b,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        //bought karna hai
        if(b==1){
            dp[i][b]= max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
        }
        else{
            dp[i][b]=max(prices[i]+solve(prices,i+2,1,dp),solve(prices,i+1,0,dp));
        }
        return dp[i][b];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};