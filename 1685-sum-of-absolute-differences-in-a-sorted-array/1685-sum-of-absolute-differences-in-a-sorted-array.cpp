class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>pref(n,0);
        vector<int>ans(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        int sum=pref[n-1];
        for(int i=0;i<n;i++){
            int suff=sum-pref[i];
            
            int pre=0;
            if(i>0){
                 pre=pref[i-1];
            }
            
            ans[i]=abs(suff-((n-i-1)*nums[i]))+abs(pre-(i*nums[i]));
        }
        return ans;
    }
};