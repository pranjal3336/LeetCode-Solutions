class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int sum =0;
        vector<int> ans;

        while(i<nums.size()){
            for(int j=i+1; j<nums.size();j++){
                sum= nums[i]+ nums[j];
                if(sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
            i++;
        }
        return ans;
        
    }
};
