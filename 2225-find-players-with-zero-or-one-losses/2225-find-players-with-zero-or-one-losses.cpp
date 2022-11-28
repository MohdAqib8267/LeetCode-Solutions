class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<matches.size();i++){
            if(mp.find(matches[i][0])==mp.end()){
                mp[matches[i][0]]=0;
            }
            mp[matches[i][1]]++;
        }
        vector<int>list1;
        vector<int>list2;
        for(auto it:mp){
            if(it.second==0){
                list1.push_back(it.first);
            }
            if(it.second==1){
                list2.push_back(it.first);
            }
        }
        ans.push_back(list1);
        ans.push_back(list2);
        return ans;
    }
};