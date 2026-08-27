class Solution {
public:
    int solve(int i  , int j , vector<vector<int>>& grid , vector<vector<int>>&dp , int n , int m){
        if(i == n-1 && j == m-1 ){
            return grid[i][j] ;
        }

        if(i>= n || j>=m ){
            return 1e9 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int right = solve(i , j+1 , grid , dp , n , m) ;
        int down =  solve(i+1 , j , grid , dp , n , m) ;

        int ans = grid[i][j] +  min(right , down) ;
        return dp[i][j] = ans ;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>>dp(n , vector<int>(m+1 , -1)) ;
        return solve(0 , 0 , grid ,  dp , n , m) ;
    }
};
