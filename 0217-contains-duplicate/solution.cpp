class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int , int>mp ;
        // int n = nums.size() ;
        // for(int i=0 ; i<n ; i++){
        //     mp[nums[i]]++ ;
        //     if(mp[nums[i]] >=2){
        //         return true ;
        //     }
        // }

        // for(auto i:mp){
        //     if(i.second >= 2){
        //         return true ;
        //     }
        // }
        // return false ;

        // unordered_set<int>st ;
        // for(int &i: nums){
        //     st.insert(i) ;
        // }

        // return st.size() != nums.size() ;

        // unordered_set<int> seen;
        // for (int num : nums) {
        //     if (seen.count(num)) return true;
        //     seen.insert(num);
        // }
        // return false;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};
