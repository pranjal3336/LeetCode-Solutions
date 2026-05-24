class Solution {
public:
    static bool cmp(vector<int> a , vector<int>b ){
        //width same toh height decending 
        if(a[0] == b[0]){
            return a[1]>b[1] ;
        }
        else{
            return a[0] < b[0] ;
        }
    }
    //iss method mai On2 aa rhi hai time complexity isliye dp with binary search se krna hoga 
    // int solve(vector<int>&height  , int curr , int prev , vector<vector<int>>&dp){
    //     if(curr == height.size()){
    //         return 0 ;
    //     }

    //     if(dp[curr][prev+1] != -1){
    //         return dp[curr][prev+1] ;
    //     }
    //     int include = 0 ;
    //     if(prev == -1 || height[curr]>height[prev]){
    //         include = 1 + solve(height , curr +1 , curr , dp) ;
    //     }

    //     int exclude = 0 + solve(height , curr+1 , prev , dp) ;

    //     return dp[curr][prev+1] =  max(include , exclude) ;
    // }

    int solve1(vector<int>&height , int n){
        if(n == 0){
            return 0 ;
        }

        vector<int>ans ; 
        ans.push_back(height[0]) ;
        for(int i =  1 ; i<n ; i++){
            if(height[i] > ans.back()){//hum ans wale ke last element ko arr ke current element se compare kr rhe h agrr arr ka element bda h toh usse push kr denge ans mai 
                ans.push_back(height[i] );
            }
            else{//yha hum jab aayenge jab arr ka element ans wale vector ke last element se chota h toh hum arr ke element se just bde element ka index nikal rhe h using lower bound inbuilt function of binary search and uss index ki jgh arr ke lement ko daal rhe h 
                int index = lower_bound(ans.begin() , ans.end() , height[i]) - ans.begin() ;
                ans[index] = height[i] ;
            }
        }

        return ans.size() ;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //step 1 widh ascending if same then height in descending 
        sort(envelopes.begin() , envelopes.end() , cmp) ;

        //step 2 sirf height wala vector bhejnege jisme LIS aaply hoga 
        vector<int>height ;
        for(auto &a : envelopes){
            height.push_back(a[1]) ;
        }

        //step 3 ab LIS apply 
        int n = height.size() ;
        // vector<vector<int>>dp(n , vector<int>(n+1 , -1)) ;
        // return solve(height , 0 , -1  , dp) ;

        return solve1(height , n) ;

    }
};
