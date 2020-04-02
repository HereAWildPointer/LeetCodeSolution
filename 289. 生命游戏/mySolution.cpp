class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result;
        for(int i=0;i<board.size();i++){
            vector<int> temp; //暂存一行
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==1){
                    int count=-1;
                    for(int m=0;m<3;m++){
                        for(int n=0;n<3;n++){
                            //计算活细胞的个数时要注意vector不要越界
                            if(i-1+m>=0 && i-1+m<board.size() && j-1+n>=0 && j-1+n<board[i].size() && board[i-1+m][j-1+n]==1){
                                count++;
                            }
                        }
                    }
                    if(count<2||count>3){
                        temp.push_back(0);
                    }
                    else{
                        temp.push_back(1);
                    }
                }
                else{
                    int count=0;
                    for(int m=0;m<3;m++){
                        for(int n=0;n<3;n++){
                            if(i-1+m>=0 && i-1+m<board.size() && j-1+n>=0 && j-1+n<board[i].size() && board[i-1+m][j-1+n]==1){
                                count++;
                            }
                        }
                    }
                    if(count==3){
                        temp.push_back(1);
                    }
                    else{
                        temp.push_back(0);
                    }
                }
            }
            result.push_back(temp);
        }
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                board[i][j]=result[i][j];
            }
        }
    }
};