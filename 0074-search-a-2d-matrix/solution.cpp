class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int l = 0 ;
        int m = nums.size() ;
        int n = nums[0].size() ;
        int r = m*n -1 ;
        while(l<=r){
            int mid = l + (r-l)/2 ;
            if(nums[mid/n][mid%n] == target){
                return true ;
            }
            else if(nums[mid/n][mid%n] > target){
                r = mid -1 ;
            }
            else{
                l = mid+1 ;
            }
        }
        return false ;
    }
};
