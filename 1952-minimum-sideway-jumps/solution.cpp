class Solution {
public:
    int solve( vector<int>& obstacles , int currLane , int currPos , vector<vector<int>>&dp){
        //base case 
        if(currPos ==  obstacles.size()-1){//last position pr aate hi ruk jayenge 
            return 0 ;
        }
        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos] ;
        }
        
        //no jump 
        if(obstacles[currPos +1] != currLane){
            return solve(obstacles , currLane , currPos + 1 , dp) ;
        }

        else{//sideways jump
            int ans = INT_MAX ;
            for(int i=1 ; i<=3 ; i++){
                if(currLane != i && obstacles[currPos] != i ){
                    ans = min( ans  , 1 + solve( obstacles , i , currPos+1 , dp)) ;
                }
            }

            return dp[currLane][currPos] = ans ;
        }

        
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() ;
        vector<vector<int>>dp(4 , vector<int>(n , -1)) ;//lane 0,1,2 and 3 and columns jitne obstacles ka size hai 
        return solve( obstacles , 2 , 0 , dp) ;
    }
};
