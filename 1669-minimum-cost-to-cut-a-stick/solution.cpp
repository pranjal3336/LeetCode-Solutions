class Solution {
public:
    int solve(vector<int>& cuts , int i , int j , vector<vector<int>>&dp){
        //base case 
        if(i+1 == j){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = INT_MAX ;

        for(int k = i+1 ; k<j ; k++){
            int cost = cuts[j] - cuts[i] + solve(cuts , i , k ,dp) + solve(cuts , k , j , dp) ;
            ans = min(ans , cost) ;
        }

        return dp[i][j] = ans ;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end()) ;
        cuts.insert(cuts.begin() , 0) ;
        cuts.push_back(n) ;
        int m = cuts.size() ;
        vector<vector<int>>dp(m+1 , vector<int>(m+1 , -1)) ;
        return solve( cuts , 0 , m-1 , dp) ;
    }
};
