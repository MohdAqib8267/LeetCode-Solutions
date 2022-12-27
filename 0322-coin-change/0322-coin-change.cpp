class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(i>=coins.size()){
            return 100000;
        }
        if(amount==0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = 100000;
        if(coins[i]<=amount){
             take = 1+solve(i,amount-coins[i],coins,dp);
        }
        int not_take=solve(i+1,amount,coins,dp);
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // int ans= solve(0,amount,coins,dp);
        // if(ans==100000){
        //     return -1;
        // }
        // return ans;
        
        //Tabulation
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j] and dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(1+dp[i-coins[j]],dp[i]);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
        
    }
};