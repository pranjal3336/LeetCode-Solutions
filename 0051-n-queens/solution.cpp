class Solution {
public:
    unordered_set<int>cols ;
    unordered_set<int>diag ;
    unordered_set<int>antidiag ;
    // bool isValid(vector<string>&board , int row , int col){
    //     //for vertical upward attack 
    //     for(int i = row-1 ; i>=0 ; i--){
    //         if(board[i][col] == 'Q'){
    //             return false ;
    //         }
    //     }
    //     //for left diagonal upwards  attack 
    //     int i = row-1 ;
    //     int j = col-1 ;
    //     while(i>=0 && j >=0){
    //         if(board[i][j] == 'Q'){
    //             return false ;
    //         }
    //         i-- ;
    //         j-- ;
    //     }
    //     //for right diagonal attack 
    //     int m = row-1 ;
    //     int n = col+1 ;
    //     while(m>=0 && n < board[0].size()){
    //         if(board[m][n] == 'Q'){
    //             return false ;
    //         }
    //         m-- ;
    //         n++ ;
    //     }
    //     return true ;
    // }
    void solve(int n , int row , vector<string>&board , vector<vector<string>>&res ){
        //base case 
        if(row >= n){
            res.push_back(board) ;//current configuration result mai push krenge 
            return ;
        }

        for(int col = 0 ; col <n ; col++){//each row ke har column mai rkhkr check kr rhe hai 
            // if(isValid(board , row , col)){//agr current cell valid hai tbhi queen rkhenge 
            //     board[row][col] = 'Q' ;
            //     solve(n , row+1 , board , res) ;
            //     board[row][col] = '.' ;//vapis jaate vqt cell ko khali kr denge more configurations ke liye 
            // }

            int diagconst = row + col ;
            int antidiagconst = row - col ;
            if(cols.find(col) != cols.end() || diag.find(diagconst) != diag.end() || antidiag.find(antidiagconst) != antidiag.end()){
                continue ;
            }
            //do 
            cols.insert(col) ;
            diag.insert(diagconst) ;
            antidiag.insert(antidiagconst) ;
            board[row][col] = 'Q' ;
            //explore 
            solve(n , row+1 , board , res) ;
            //backtracking yaani undo kr rhe hai 

            
            cols.erase(col) ;
            diag.erase(diagconst) ;
            antidiag.erase(antidiagconst) ;
            board[row][col] = '.' ;

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res ;
        vector<string>board(n , string(n , '.')) ;
        solve(n , 0 , board , res) ;
        return res ;
    }
};
