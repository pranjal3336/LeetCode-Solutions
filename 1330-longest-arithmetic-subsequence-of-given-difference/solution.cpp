class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int , int>dp ;
        int ans = 0 ;

        for(int i=0 ;i<arr.size() ;i++){
            int prev = arr[i] - difference ; //humne current element mai difference subtract kra hai and check kr rhe hai ki jo ab aaya hai voh array mai exist krta hai ya nhi 

            if(dp.count(prev)){
                dp[arr[i]] = 1 + dp[prev] ;
            }
            else{
                dp[arr[i]] = 1; 
            }

            ans = max(ans , dp[arr[i]]) ;

        }

        return ans ;
    }

};
