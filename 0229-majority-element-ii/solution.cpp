class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       //TC O(N) and SC O(N) 
       
       
       int n = nums.size() ;
       int x = n/3 ;
       unordered_map<int , int>m ;
        vector<int>ans ;
       for(int i = 0 ; i<n ; i++){
        m[nums[i]]++ ;
        if(m[nums[i]] == x+1){
            ans.push_back(nums[i]) ;
        }
       }
    //    for(auto it : m) {
    //         // it.second frequency hai, aur it.first actual number hai
    //         if(it.second > x) {
    //             ans.push_back(it.first);
    //         }
    //     }
       return ans ;
    }
};
