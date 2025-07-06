class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count =1;
        int maxicount=0;
        int element =0;
        if(n==1){
                element = nums[0];
                return element ;
            }
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                count =1;
            }
            if(count>maxicount){
                maxicount= count;
                element = nums[i];
            }
        }
        return element; 
    }
};
