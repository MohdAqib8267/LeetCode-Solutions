class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            if(mp.find(temp)!=mp.end()){
                mp[arr[i]]=mp[temp]+1;
            }
            else{
                mp[arr[i]]=1;
            }
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        return maxi;
    }
};