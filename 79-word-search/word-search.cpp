class Solution {
public:
    int rows,cols;
    vector<vector<bool>>visited;
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        visited=vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(r,c,0,word,board)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int r,int c,int i, string word,vector<vector<char>>& board){
        if(i==word.size()){
            return true;
        }
        if(r<0||c<0||r>=rows||c>=cols||board[r][c]!=word[i]||visited[r][c]){
            return false;
        }
        visited[r][c]=true;
        bool res=dfs(r+1,c,i+1,word,board)||dfs(r-1,c,i+1,word,board)||dfs(r,c+1,i+1,word,board)||dfs(r,c-1,i+1,word,board);
        visited[r][c]=false;
        return res;
    }
};