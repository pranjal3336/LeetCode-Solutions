class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=1;
        int count =1;
        int index = 0 ;
        if(n==0){
            return 0;
        }
        while(i<n){
            if(nums[i-1]+1==nums[i]){
                i++;
                count++;
            }
            else if(nums[i-1]==nums[i] && i<n){
                i++;
            }
        
            else if (nums[i-1]+1 != nums[i] ){
                if(index < count ){
                    index = count ;
                }
                count =1;
                i++;

            }
        }
        if( index >count){
            return index;
        }
        else{
            return count ;
        }


    }
};
