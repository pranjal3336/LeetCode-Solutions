class Solution {
public:
    static bool check(vector<int>newbase , vector<int>base){
        if(newbase[0] <=base[0] && newbase[1]<=base[1] && newbase[2]<=base[2] ){
            return true ;
        }
        else{
            return false ;
        }
    }

    int solve(vector<vector<int>>& arr , int curr , int prev , vector<vector<int>>&dp){
        if(curr == arr.size()){
            return 0 ;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1] ;
        }
        int include = 0 ;
        if(prev == -1 || check(arr[prev] , arr[curr] )){
            include = arr[curr][2] + solve(arr , curr+1 , curr , dp) ; //hume 1 nhi add krna height add krni hai 
        }

        int exclude = 0 + solve(arr , curr+1 , prev , dp) ;

        return dp[curr][prev+1]= max(include , exclude) ;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //each line ko sort kra hai last mai height aaygi jo bdi hogi teeno mai 
        for(auto &a : cuboids ){
            sort(a.begin() , a.end()) ;
        }

        sort(cuboids.begin() , cuboids.end()) ;//ab w or l ke according sort kra h 

        //ab lis lagaenge
        int n = cuboids.size() ;
        vector<vector<int>>dp(n , vector<int>(n+1 , -1)) ; 
        return solve(cuboids , 0 , -1 , dp) ;

    }
};
