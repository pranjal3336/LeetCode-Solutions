class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int ans =-1  ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>target){
                ans = 0;
            }
            
            if(nums[i]==target){
                ans = i ;
                break ;
            }
            if(nums[i]>target){
                ans = i ;
                break;
            }
            else{
             ans = n  ;
            }
        }
        return ans ;
    }
};
