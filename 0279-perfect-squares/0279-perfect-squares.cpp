class Solution {
public:
    int solve(int i,int sum,vector<int>& arr,int n,vector<vector<int>>& dp){
        if(i>=n or sum<0){
            return 1000;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum==0){ 
            return 0;
        }
        //take
        int take=1+solve(i,sum-arr[i],arr,n,dp);
        //not take
        int not_take=solve(i+1,sum,arr,n,dp);
        return dp[i][sum]=min(take,not_take);
    }
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(n+1,-1));
        return solve(0,n,arr,arr.size(),dp);
    }
};