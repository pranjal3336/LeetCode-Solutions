class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int ans =0;
        for(int i=1;i<= nums.size();i++){
            if(nums[i-1]==1){
                count=count+1;
                if(count>ans){
                    ans = count ;
                } 
            }
            else{
                count = 0;
            }
        }
        return ans ;
    }
};
