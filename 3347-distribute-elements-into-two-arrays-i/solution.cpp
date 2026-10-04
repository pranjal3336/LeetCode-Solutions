class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size() ;
        if(n <=2){
            return nums ;
        }
        
        vector<int>arr1 ;
        arr1.push_back(nums[0]) ;

        vector<int>arr2 ;
        arr2.push_back(nums[1]) ;

        for(int i=2 ; i<n ; i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]) ;
            }
            else{
                arr2.push_back(nums[i]) ;
            }
        }

        vector<int>ans ;

        for(int i : arr1){
            ans.push_back(i) ;
        }

        for(int i : arr2){
            ans.push_back(i) ;
        }

        return ans ;

    }
};
