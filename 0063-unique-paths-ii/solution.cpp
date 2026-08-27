class Solution {
public:
     int solve(int i  , int j , vector<vector<int>>& obstacleGrid  , vector<vector<int>>&dp , int n , int m){
        if(i == n-1 && j == m-1 && obstacleGrid[i][j] == 0){
            return 1 ;
        }

        if(i>= n || j>=m || (obstacleGrid[i][j] ==1)){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int right = solve(i , j+1 , obstacleGrid , dp , n , m) ;
        int down = solve(i+1 , j ,obstacleGrid , dp , n , m) ;

        int ans = right + down ;
        return dp[i][j] = ans ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() ;
        int m = obstacleGrid[0].size() ;
        vector<vector<int>>dp(n , vector<int>(m+1 , -1)) ;
        return solve(0 , 0 , obstacleGrid ,  dp , n , m) ;
    }
};
