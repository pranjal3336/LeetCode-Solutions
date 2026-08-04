class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        // sort(nums.begin() , nums.end()) ;
        // int n= nums.size() ;
        // vector<int>ans ;
        // for(int i=nums[0] ;i<=nums[n-1] ; i++){
        //    ans.push_back(i) ;
        // }

        // int i = n-1 ;
        // int j = ans.size()-1 ;
        // vector<int>ans1 ;
        // while(i>=0 && j>=0 ){
        //     if(nums[i] == ans[j]){
        //         i-- ;
        //         j-- ;
        //     }
        //     else if(ans[j]>nums[i]){
        //         ans1.push_back(ans[j]) ;
        //         j-- ;
        //     }
        // }
        // sort(ans1.begin() , ans1.end()) ;
        // return ans1 ;

        int mini = nums[0] , maxi = nums[0] ;
        unordered_set<int>s ;
        for(int x : nums){
            s.insert(x);
            mini = min(mini , x) ;
            maxi = max(maxi , x) ;
        }

        vector<int>ans ;
        for(int i = mini ; i<=maxi ; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};
