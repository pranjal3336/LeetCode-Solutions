class Solution {
public:
    int solve(int index ,   vector<int>& days, vector<int>& costs , vector<int>&dp){
        //base case 
        if(index >= days.size()){
            return 0 ;
        }

        if(dp[index] != -1){
            return dp[index] ;
        }

        //1 day pass
        int opt1 = costs[0] + solve(index+1 , days , costs ,dp) ;

        //7 day pass
        int i ;
        for( i = index ; i<days.size() && days[i] < days[index]+7 ; i++) ;

        int opt2 = costs[1] + solve(i , days , costs ,dp) ;

        //30 day pass
        
        for( i = index ; i<days.size() && days[i] < days[index]+30 ; i++) ;

        int opt3 = costs[2] + solve(i , days , costs ,dp) ;


        return dp[index] = min(opt1 , min(opt2 , opt3)) ;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ;
        vector<int>dp(n+1   , -1) ;
        return solve( 0,  days , costs , dp)  ;
    }
};
