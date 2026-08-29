class Solution {
public:
    int solve(int n , vector<int>&dp){
        if(n == 0){
            return 1 ;
        }

        if(n<0){
            return 0 ;
        }

        if(dp[n] != -1){
            return dp[n] ;
        }

        int onestep = solve(n-1 , dp) ;
        int twostep = solve(n-2 , dp) ;

        int ans = onestep+twostep ;

        return dp[n] = ans ;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1 , -1) ;
        // return solve(n , dp) ;

        double  a = (1.0+sqrt(5.0))/2.0 ;
        double b = (1.0-sqrt(5.0))/2.0 ;

        int  ans = round(((pow(a , n+1) - pow(b , n+1))/sqrt(5.0))) ;

        return ans ;

    }
};
