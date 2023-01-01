class Solution {
public:
    bool wordPattern(string pattern, string s) {
         map<string,char>mpp;
        int n=s.size();
        int m=pattern.size();
        int j=0;
        for(int i=0;i<n;i++){
            string temp="";
            while(s[i]!=' ' and s[i]!='\0'){
               temp+=s[i++];
            }
            // check for word to letter
            if(mpp.find(temp)!=mpp.end()){
                if(mpp[temp]!=pattern[j]) return false;
                else j++;
            }else{
                mpp[temp]=pattern[j];
                j++;
            }
        }
        if(j<m) return false; // if cnt of words != m
        
     
        vector<int>v(26,0);
        for(auto it:mpp){
            v[it.second-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]>1) return false;
        }
        return true;
    }
};