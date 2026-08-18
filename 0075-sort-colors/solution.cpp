class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int curr =0;
        // int zeroindex =0;
        // int secondindex = nums.size()-1;
        // while(curr<=secondindex){
        //     if(nums[curr]==0){
        //         swap(nums[curr],nums[zeroindex]);
        //         curr++;
        //         zeroindex++;
        //     }
        //     else if(nums[curr]==1){
        //         curr++;
        //     }
        //     else if(nums[curr]==2){
        //         swap(nums[curr], nums[secondindex]);
        //         secondindex--;
        //     }
        // }

        unordered_map<int , int>mp ;
        for(int i= 0 ; i<nums.size() ; i++){
            mp[nums[i]]++ ;
        }

        int i = 0 ;
        while(i<nums.size()){

            while(mp[0] >0){
                nums[i] = 0 ;
                i++ ;
                mp[0]-- ;
            }

            while(mp[1] >0){
                nums[i] = 1 ;
                i++ ;
                mp[1]-- ;
            }
            while(mp[2] >0){
                nums[i] = 2 ;
                i++ ;
                mp[2]-- ;
            }
        }

        
    }
};
