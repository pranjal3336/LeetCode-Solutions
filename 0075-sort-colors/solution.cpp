class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr =0;
        int zeroindex =0;
        int secondindex = nums.size()-1;
        while(curr<=secondindex){
            if(nums[curr]==0){
                swap(nums[curr],nums[zeroindex]);
                curr++;
                zeroindex++;
            }
            else if(nums[curr]==1){
                curr++;
            }
            else if(nums[curr]==2){
                swap(nums[curr], nums[secondindex]);
                secondindex--;
            }
        }
    }
};
