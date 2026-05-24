class Solution {
public:
    int solve(vector<vector<int>>& matrix , int i , int j , int &maxi , vector<vector<int>>&dp){
      //base case 
      if(i>=matrix.size() || j >=matrix[0].size()){
          return 0 ;
      }
      
      if(dp[i][j] != -1){
          return dp[i][j] ;
      }
      
      int right = solve(matrix , i , j+1 , maxi , dp) ;
      int diagonal = solve(matrix , i+1 , j+1 , maxi , dp ) ;
      int down = solve(matrix , i+1 , j , maxi , dp) ;
      
      int ans = 0 ;
      if(matrix[i][j] == 1){
          ans = 1 + min(right , min(diagonal , down))  ;
          maxi += ans ;
          return dp[i][j] = ans ;
      }
      else{
          return dp[i][j] =  0 ;
      }
      
    }
    int countSquares(vector<vector<int>>& matrix) {
        int maxi = 0 ;
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<int>>dp(n , vector<int>(m , -1)) ;
        solve(matrix , 0 , 0 , maxi , dp) ;
        return maxi ;
    }
};
