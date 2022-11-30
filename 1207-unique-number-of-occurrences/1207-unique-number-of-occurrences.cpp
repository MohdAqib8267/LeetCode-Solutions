class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_map<int,bool>chk;
        for(auto it:mp){
            if(chk[it.second] == true){
                return false;
            }
            chk[it.second]=true;
        }
        return true;
    }
};