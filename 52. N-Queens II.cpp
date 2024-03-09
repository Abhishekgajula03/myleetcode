class Solution {
public:
    int nqueen(int col,vector<vector<string>>&ans, vector<int>&board, vector<int>&left, vector<int>&diagonalup, vector<int>&diagonaldown,int n){
        int count=0;
        if(col==n){return 1;}
        for(int row=0;row<n;row++){
     if(left[row]==0&&diagonalup[n-1+col-row]==0&&diagonaldown[row+col]==0){
       
        left[row]=1;
        diagonalup[n-1+col-row]=1;
        diagonaldown[row+col]=1;
       
        count+=nqueen(col+1,ans,board,left,diagonalup,diagonaldown,n);
     
        left[row]=0;
        diagonalup[n-1+col-row]=0;
        diagonaldown[row+col]=0;
        }
    }
    return count;}
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<int>board(n);
       
        vector<int>left(n,0),diagonalup(2*n-1,0),diagonaldown(2*n-1,0);
        return nqueen(0,ans,board,left,diagonalup,diagonaldown,n);
        
    }
};
