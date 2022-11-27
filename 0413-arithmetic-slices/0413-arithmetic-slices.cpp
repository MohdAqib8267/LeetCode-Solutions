class Solution {
public:
  int solve(int i,int n,vector<int>& nums,vector<int>& dp,int res){
        if(i>n-3){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
            res++;
            return dp[i]=res+solve(i+1,n,nums,dp,res);
        }
        else{
            return dp[i]=solve(i+1,n,nums,dp,0);
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        //memoization
        int n=nums.size();
        // int res=0;
        // vector<int>dp(n,-1);
        // return solve(0,n,nums,dp,res);

        //Tabulation
        vector<int>dp(n,0);
        int res=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=1+dp[i-1];
                res=res+dp[i];
            }
        }
        return res;
    }
};