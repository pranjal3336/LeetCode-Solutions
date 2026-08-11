class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>s ;
        int n = nums.size() ;
        //set mai nums ke element daal rhe hai 
        for(int i : nums){
            s.insert(i) ;
        }

        int sum = nums[0] ; //sum mai nums[0] add krenge and jb tk sum mai nums ke element add krenge jb tk element mai 1 ka difference hoga and then ussi sum ko search krna hai 
        int i = 1 ;
        while(i < n && nums[i-1] + 1 == nums[i]){
            sum+=nums[i] ;
            i++ ;
        }
        //yha set mai duplicate nhi aaye honge jiski help milegi km traverse krne honge and agr sum jitna element present nhi hoga toh loop break and vhi sum answer hoga and agr sum present hua toh sum + 1 krenge and dubara check krenge ki set mai present hai ya nhi 
        while(s.find(sum) != s.end()){
            sum++ ;
        }
        return sum ;
    }
};
