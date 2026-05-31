class Solution {
public:
    int solve(int i , int j , int m , vector<vector<int>>& matrix , vector<vector<int>>&dp ){
        //base case 
        if(j>=m || j<0){
            return 1e9 ;
        }
        //hume bas last row mai pahuchna hai column koi bhi ho frk nhi pdta 
        if(i == m-1){
            return matrix[i][j] ;
        }

        if(dp[i][j] != 1e9){
            return dp[i][j] ;
        }

        //ab 3 choice hai
        int down = solve(i+1 , j , m , matrix , dp) ;//same olumn but next row 

        int leftdiagonal = solve(i+1 , j-1 , m , matrix ,dp ) ;
        int rightdiagonal = solve(i+1 , j+1 , m , matrix ,dp) ;

        int ans = matrix[i][j] + min(down , min(leftdiagonal , rightdiagonal)) ;

        return dp[i][j] = ans ;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int m = matrix.size() ;
       int finalans = INT_MAX ;
       vector<vector<int>>dp(m+1 , vector<int>(m+1 , 1e9)) ;
       for(int j = 0 ; j<m ; j++){
            finalans = min(finalans , solve(0,j,m , matrix, dp) )  ;//row and column same hai square matrix hai isliye sirf ek baar hi m pass krenge 
       }
        return finalans ;

    }
};
