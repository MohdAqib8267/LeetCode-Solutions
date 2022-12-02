class Solution {
public:
    bool closeStrings(string word1, string word2) {
       
        
        //kuchhh b ho but dono me character same hone chahye or dono words ki length bhi same honi chahye 
         unordered_map<char,int> m1, m2;

        if(word1.size()!=word2.size()) return 0;

        for(int i=0; i<word1.size(); i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        for(auto i : m1){
            if(m2.find(i.first)==m2.end()) return 0;
        }

        if(m1.size()!=m2.size()) return 0;
        
        
  //ab map 2 ke element ki freq freq_check me match krni chaye and wo element present b ho ye check kr lenge usinf char_check
        unordered_map<int,int> m;//check freq
        for(auto i : m1){
            m[i.second]++;
        }
        for(auto i : m2){
            m[i.second]--;
            if(m[i.second]==0) m.erase(i.second);
        }

        return m.empty();
    }
       
      
};