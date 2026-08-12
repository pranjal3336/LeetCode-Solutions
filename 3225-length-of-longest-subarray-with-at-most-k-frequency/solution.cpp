class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int , int>mp ;
        int ans = INT_MIN ;
        int j =0 ;
        for(int i =0 ; i< n ; i++){
            while ( j <n && mp[nums[j]] + 1 <= k){
                mp[nums[j]]++ ;
                j++ ;
            }
            mp[nums[i]]-- ;
            ans = max(ans , j-i) ;

        }

        return ans ;
    }
};
