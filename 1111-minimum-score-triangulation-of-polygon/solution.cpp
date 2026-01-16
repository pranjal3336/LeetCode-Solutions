class Solution {
public:
    int solve(vector<int>& values , int i , int j , vector<vector<int>>&dp){//hum i , j ko starting mai base le rhe h and i and j first and last element h values wale vector ke and k ek teesre vertex ka kaam krega jo ki i and j ke beech ka koi bhi element ho skta h isliye humne for loop lgaya h
    //answer jo bnega voh teeno vertex ko multiply krke bnega and jb hum triangle bnayenge toh saath mai sub problem generate hogi jo koi aur polugon hoga isliye humene values[i]*values[j]*values[k] + solve(values , i , k) + solve(values , k , j) yeh likha h
        //base case --> agr 2 hi vertex hue toh 0 return krenge kyonki triangle possible nhi h
        if(i+1 == j){//mtlb values wale vecto ke startingelement ko i and last element ko j se show kr rheand agr i ka next hi j hai toh mtlb 2 element h
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = INT_MAX ;
        for(int k = i+1 ; k<j ; k++){
             ans = min(ans , values[i]*values[j]*values[k] + solve(values , i , k , dp) + solve(values , k , j , dp)) ;
        }

        dp[i][j] = ans ;

        return dp[i][j] ;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size() ;
        vector<vector<int>>dp(n , vector<int>(n  , -1)) ;

        return solve(values , 0 , n-1 , dp) ;
    }
};
