class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        vector<int>ans;
        for(int l=0;l<nums.size();l++){
            if(nums[l]>=0){
                arr1.push_back(nums[l]);
            }
            else{
                arr2.push_back(nums[l]);
            }
        }
        int i=0;
        int j=0;
        while(i<arr1.size() && j<arr2.size()){
            ans.push_back(arr1[i]);
            ans.push_back(arr2[j]);
            i++;
            j++;

        }
        return ans ;

    }
};
