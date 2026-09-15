class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , int>mp ;
        int mod = 1e9+7 ;
        int res = 1 ;
        //1. Store LAST occurrence of every element (Right to Left traversal)
        for(int i = n-1 ; i>=0 ; i--){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i ;
            }
        }
        
        int i =0 ;
        int j = mp[nums[0]] ;// 2. 'j' tracks the MAX REACH of the current partition
        while(i<n){
            // 3. GAP FOUND! 'i' crossed the boundary 'j'. 
            // We can split here -> Combinations double ho jayenge (*2)
            if(i>j){
                res = (res*2)%mod ;
            }
            // 4. Expand partition boundary if current element goes further
            j = max(mp[nums[i]], j) ;
            i++ ;
        }
        return res ;
    }
};
