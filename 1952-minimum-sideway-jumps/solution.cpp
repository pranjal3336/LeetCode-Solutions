class Solution {
public:
    int solve(vector<int>& obstacles , int currlen , int currpos  , vector<vector<int>>&dp , int n ){
        
    //base case 
    if(currpos == n-1){//iska mtlb hum kisi bhi lane mai ho pr hum last position pr aa chuke h toh ruk jayenge humara answer nikl chuka hoga 
        return 0 ;
    }

    if(dp[currlen][currpos] != -1){
        return dp[currlen][currpos] ;
    }

    int ans = INT_MAX ;
    if(obstacles[currpos +1] != currlen){//isme hum check kr rhe h jha se humne start kra h yaani lane 2 agr ussi lane mai but next position mai agr koi obstacle nhi h toh hum aage bd jayenge 
        return solve(obstacles , currlen , currpos+1 , dp , n) ;
    }
    else{
        //ab hum side ways jump krenge 
        for(int i = 1 ; i<=3 ;i++){//hum teeno lane mai check kr rhe h jha obstacle nhi vha chle jayenge 
            if(currlen != i && obstacles[currpos] != i){//hum yeh bhi dekh rhe h ki jis lane mai khde h usse nhi lena dubara jaise agr lane 2 mai h toh hum lane 1 and3 check krenge and dono se answer nikalenge jha minimum jump aayegi voh answer hoga 
                ans = min(ans , 1+solve(obstacles , i , currpos , dp , n)) ;//jo yeh i hai yeh remaiing 2 lanes mai se koi hogi jha hum khde nhi h
            }
        }
        dp[currlen][currpos] = ans ;
    }

    return dp[currlen][currpos] ;

    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() ;
        vector<vector<int>>dp(4 , vector<int>(n , -1)) ;
        return solve(obstacles , 2 , 0 , dp , n);
    }
};
