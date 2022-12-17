class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-")
            st.push(stoi(tokens[i]));
            else{
                long long int op2=st.top();
                st.pop();
                long long int op1=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(op1+op2);
                }
                else if(tokens[i]=="-"){
                    st.push(op1-op2);
                }
                else if(tokens[i]=="*"){
                    st.push(op1*op2);
                }
                else{
                    st.push(op1/op2);
                }
            }
        }
        return st.top();
    }
};