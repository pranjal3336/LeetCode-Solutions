class Solution {
public:
    int solve(int i , int prevJump ,int n , vector<int>& stones ,unordered_map<int , int>&mp , vector<vector<int>>&dp){
        if(i ==n-1){
            return true;
        }

        if(dp[i][prevJump] != -1){
            return dp[i][prevJump] ;
        }

        bool res = false ;

        for(int nextJump = prevJump -1 ; nextJump <= prevJump+1; nextJump++){
            if(nextJump >0){

                int nextStone = stones[i] + nextJump ;

                if(mp.find(nextStone) != mp.end()){
                    res = res || solve(mp[nextStone] , nextJump , n , stones ,mp , dp) ;
                }
            }
        }

        return dp[i][prevJump] =  res ;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int , int>mp ;
        int n = stones.size() ;
        for(int i=0 ; i<n ; i++){
            mp[stones[i]] = i ;
        }
        vector<vector<int>>dp(n , vector<int>(n , -1)) ;
        return solve(0 , 0 , n , stones , mp , dp) ;
    }
};
