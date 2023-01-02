class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int cntCap=0;
        int cntSmall=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' and word[i]<='Z'){
                cntCap++;
            }
            if(word[i]>='a' and word[i]<='z'){
                cntSmall++;
            }
        }
        if(cntCap==n){
            return true;
        }
        if(cntSmall==n){
            return true;
        }
        if((word[0]>='A' and word[0]<='Z') and cntSmall==n-1){
            return true;
        }
        return false;
    }
};