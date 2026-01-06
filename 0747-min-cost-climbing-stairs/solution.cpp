class Solution {
public:
    // //mthod 2 DP : using tabulation 

    // int solve(vector<int>& cost , int n){
    //     vector<int>dp(n);
    //     dp[0] = cost[0] ;
    //     dp[1] = cost[1] ;

    //     for(int i=2 ;i<n ;i++){
    //         dp[i] = cost[i] + min(dp[i-1] , dp[i-2]) ;
    //     }

    //     return min(dp[n-1] , dp[n-2]) ;



    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size()  ;
    //     int ans = solve(cost , n) ;
    //     return ans ;

    // }

    //mthod 3 DP : space optimization only variables 

    int solve1(vector<int>& cost , int n){
        
        int prev2 = cost[0] ;
        int prev1  = cost[1] ;

        for(int i=2 ;i<n ;i++){
            int curr  = cost[i] + min(prev1 , prev2) ;
            prev2 = prev1 ;
            prev1 = curr ;
        }

        return min(prev1 , prev2) ;



    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()  ;
        int ans = solve1(cost , n) ;
        return ans ;

    }
};
