class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        // sort(nums.begin() , nums.end()) ;
        // return (nums[n-1] -1)*(nums[n-2] -1) ;
        int first_greater = INT_MIN ;
        int second_greater = INT_MIN ;
        for(int i=0 ; i<n ; i++){
            if(nums[i] > first_greater){
                second_greater = first_greater ;
                first_greater = nums[i] ;
            }
            else if(nums[i]>second_greater ){
                second_greater = nums[i] ;
            }
        }

        return (first_greater -1)*(second_greater-1) ;

    }
};
