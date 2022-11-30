class Solution {
public:
    string pushDominoes(string s) {
        //1st method using left right array
//         int n=s.size();
//         vector<int>left(n,0);
//         vector<int>right(n,0);
//         string ans="";
        
//         char prev='.';
//         int count=0;
//         //right falling
//        for(int i=0;i<n;i++){
//             if(s[i]=='R'){
//                 prev='R';
//                 count=1;
//                 continue;
//             }
//             else if(s[i]=='L'){
//                 prev='L';
//             }
//             if(prev=='R' and s[i]=='.'){
//                 right[i]=count++;
//             }
//         }
//         //left falling
//         prev='.';
//         count=1;
//          for(int i=n-1;i>=0;i--){
//             if(s[i]=='L'){
//                 prev='L';
//                 count=1;
//                 continue;
//             }
//             else if(s[i]=='R'){
//                 prev='R';
                
//             }
//             if(prev=='L' and s[i]=='.'){
//                 left[i]=count++;
//             }
//         }
        
//         //now traverse
//         for(int i=0;i<n;i++){
//             if(left[i]==0 and right[i]==0){
//                 ans+=s[i];
//             }
//             else if(left[i]==0){
//                 ans+='R';
//             }
//             else if(right[i]==0){
//                 ans+='L';
//             }
//             else if(left[i]==right[i]){
//                 ans+='.';
//             }
//             else if(left[i]>right[i]){
//                 ans+='R';
//             }
//             else{
//                 ans+='L';
//             }
//         }
//         return ans;
        
        //2nd method using deque
        int n=s.size();
        deque<int>q;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                q.push_back(i);
            }
        }
        
        while(!q.empty()){
            int k=q.front();
            q.pop_front();
            if(s[k]=='L' and k>0 and s[k-1]=='.'){
                s[k-1]='L';
                q.push_back(k-1);
            }
            else if(s[k]=='R'){
                if(s[k+1]=='.' and k+1<n){
                    if(s[k+2]=='L' and k+2<n){
                        q.pop_front();
                    }
                    else{
                        s[k+1]='R';
                        q.push_back(k+1);
                    }
                }
            }
        }
        return s;
    }
};