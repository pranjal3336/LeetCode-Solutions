class Solution {
public:
    int solve(vector<int>& piles , int i , int j , vector<vector<int>>&dp ){
        if(i>j){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        int take_i = piles[i] + min(solve(piles , i+2 , j , dp) , solve(piles , i+1 , j-1 , dp)) ;

        int take_j = piles[j] + min(solve(piles , i+1 , j-1 , dp) , solve(piles , i , j-2 , dp)) ;

        return dp[i][j] = max(take_i , take_j) ;
    }
    bool stoneGame(vector<int>& piles) {
        // // Since Alice can always choose to take either all even or all odd index piles
        // // and ensure a win because the total sum is odd, the answer is always true.
        // return true ;

        //method2 
        int n = piles.size() ;
        int sum = accumulate(piles.begin() , piles.end() , 0) ;
        vector<vector<int>>dp(n , vector<int>(n , -1)) ;

        int alice_score = solve(piles , 0 , n-1 , dp);//i and j index bhej rha hu i =0 and j = n-1 hoga 

        if(alice_score> sum/2){
            return true ;
        }

        return false ;
    }
};
