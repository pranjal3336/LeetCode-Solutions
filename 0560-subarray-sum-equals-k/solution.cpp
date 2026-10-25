class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int i =0 ;
        int ans = 0 ;
        unordered_map<int , int>mp ;
        mp[0] = 1 ;
        int sum = 0 ;
        while(i<n){
            sum += nums[i] ;
            
            if(mp.find(sum - k) != mp.end()){
                ans+=mp[sum-k] ;
            }
            mp[sum]++ ;
            i++ ;
        }

        return ans ;
    }
};
