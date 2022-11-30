class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            else{
                nums[i]=1;
            }
        }
        int sum=0;
        int max_len=0;
        int end_ind=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            
            if(sum==0){
                max_len=i+1;
                end_ind=i;
            }
            
            if(mp.find(sum)!=mp.end()){
                if(max_len<i-mp[sum]){
                    max_len=i-mp[sum];
                    end_ind=i;
                }
            }
            else{
                mp[sum]=i;
            }
        }
        return max_len;
    }
};