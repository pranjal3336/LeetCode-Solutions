class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int , int>mp;
        // int n = nums.size() ;
        // for(int i : nums){
        //     mp[i]++ ;
        // }

        // for(auto i:mp){
           
        //     if(i.second == 1){
        //         return i.first  ;
        //     }
            
        // }

        // return 0 ;

        // sort(begin(nums) , end(nums)) ;
        // int i = 0 ;
        // int n = nums.size() ;
        // while(i<n){
        //     if(i == n-1 || nums[i] != nums[i+1]){
        //         return nums[i] ;
        //     }
        //     i+=3 ;
        // }
        // return 0 ;

        int ans =0 ;
        int n = nums.size() ;
        for(int k = 0 ; k<= 31 ; k++){
            int temp = (1<<k) ;
            int cntones = 0 ;
            for(int num : nums){
                if((num&temp) != 0){
                    cntones++ ;
                }
            }

            if(cntones%3  != 0){
                ans = (ans|temp) ;
            }

        }

        return ans ;
    }
};
