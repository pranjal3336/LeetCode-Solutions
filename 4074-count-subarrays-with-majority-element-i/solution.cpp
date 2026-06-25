class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
       
        int ans = 0 ;
        for(int i =0 ; i<nums.size() ; i++){
            int cnt = 0 ;
            for(int j = i ; j<nums.size() ; j++){
                int length = j - i +1 ;
                if(nums[j]==target){
                    cnt++ ;
                }
                if(cnt > length /2){
                        ans++ ;
                }

            }
        }
        return ans ;
    }
};
