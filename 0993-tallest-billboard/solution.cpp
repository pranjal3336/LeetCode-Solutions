class Solution {
public:
    int solve(int i , int n, vector<int>&rods , int diff , vector<vector<int>>&dp){
        if(i>=n){
            if(diff == 0){
                return 0  ;
            }
            return INT_MIN ;
        }

        if(dp[i][diff+5000] != -1){
            return dp[i][diff+5000] ;
        }

        int a = rods[i] +  solve(i+1 , n , rods , diff + rods[i] , dp) ;
       
        int b = rods[i] +  solve(i+1 , n , rods ,  diff - rods[i] , dp) ;
        
        int c = solve(i+1 , n , rods,diff , dp) ;

        return dp[i][diff+5000] =  max(a , max(b,c)) ;

    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size() ;
      
        vector<vector<int>>dp(n ,vector<int>(10003 , -1)) ;
        return solve(0 , n , rods ,0, dp)/2  ;
    
    }
};
