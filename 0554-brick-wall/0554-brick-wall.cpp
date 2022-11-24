class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>mp;
        int maxSplit=0;
        for(auto list:wall){
            int pos=0;
            for(int j=0;j<list.size()-1;j++){
                int val=list[j];
                pos=pos+val;
                mp[pos]=mp[pos]+1;
                maxSplit=max(maxSplit,mp[pos]);
            }
        }
        return (wall.size()-maxSplit);
    }
};