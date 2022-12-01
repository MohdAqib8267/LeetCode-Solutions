class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int cnt1=0;
        int cnt2=0;
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='o' or s[i]=='u' or s[i]=='i'
              or s[i]=='A' or s[i]=='E' or s[i]=='O' or s[i]=='U' or s[i]=='I' ){
                mp[s[i]]=true;
            }
        }
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(mp.find(s[i])!=mp.end()){
                    cnt1++;
                }
            }
            else{
                if(mp.find(s[i])!=mp.end()){
                    cnt2++;
                }
            }
        }
        return cnt1==cnt2;
    }
};