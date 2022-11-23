class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //map for checking row and col
        map<int,set<int>>mp_row,mp_col;
        
        //map for checking submatrix
        map<pair<int,int>,set<int>>mp_sub;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int num=board[i][j];
                if(num=='.'){
                    continue;
                }
                //check rows
                if(mp_row.find(i) != mp_row.end()){
                    if(mp_row[i].count(num)==1) return false;
                    else{
                        mp_row[i].insert(num);
                    }
                }
                else{
                    mp_row[i].insert(num);
                }
                //check for columns
                if(mp_col.find(j)!= mp_col.end()){
                    if(mp_col[j].count(num)==1) return false;
                    else{
                        mp_col[j].insert(num);
                    }
                }
                else{
                    mp_col[j].insert(num);
                }
                
                //check for submatrix
                if(mp_sub.find({i/3,j/3})!=mp_sub.end()){
                    if(mp_sub[{i/3,j/3}].count(num)==1){
                        return false;
                    }
                    else{
                        mp_sub[{i/3,j/3}].insert(num);
                    }
                }
                else{
                    mp_sub[{i/3,j/3}].insert(num);
                }
            }
        }   
        return true;
    }
};