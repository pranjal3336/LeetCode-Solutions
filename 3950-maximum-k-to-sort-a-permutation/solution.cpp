class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int k = -1 ; //eg k =111111 all bits set hai -1 mai bhi all bits set hoti hai 

        for(int i =0 ; i<n ; i++){
            if(nums[i] != i){
                k = (k & nums[i]) ;
            }
        }

        return k == -1?0:k ;
    }
};
