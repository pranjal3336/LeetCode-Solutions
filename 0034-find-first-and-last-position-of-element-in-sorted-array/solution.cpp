class Solution {
public:
    int leftmostpos(vector<int>& nums, int target){
        int l = 0 ;
        int r = nums.size() -1 ;
        int ans = -1 ;

        while(l<=r){
            int mid = l +(r-l)/2 ;
    
            if(nums[mid] == target){
                ans = mid ;
                r = mid -1 ;
            }
            else if(nums[mid] > target){
                r = mid - 1  ;
            }
            else{
                l = mid+1 ;
            }
        }
        return ans ;
    }
    int rightmostpos(vector<int>& nums, int target){
        int l = 0 ;
        int r = nums.size() -1 ;
        int ans = -1 ;

        while(l<=r){
            int mid = l +(r-l)/2 ;
    
            if(nums[mid] == target){
                ans = mid ;
                l = mid + 1 ;
            }
            else if(nums[mid] > target){
                r = mid - 1  ;
            }
            else{
                l = mid+1 ;
            }
        }
        return ans ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        // int left = leftmostpos(nums , target) ;
        // int right = rightmostpos(nums , target) ;
        // return {left , right} ;

        auto l = lower_bound(nums.begin() , nums.end() , target) ;
        auto r = upper_bound(nums.begin() , nums.end() , target) ;

        if (l == nums.end() || *l != target) {
        return {-1, -1};
        
        }
        return {static_cast<int>(l - nums.begin()), static_cast<int>(r - nums.begin() - 1)};
    }
};
