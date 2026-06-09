class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int>arr1;
        // vector<int>arr2;
        // vector<int>ans;
        // for(int l=0;l<nums.size();l++){
        //     if(nums[l]>=0){
        //         arr1.push_back(nums[l]);
        //     }
        //     else{
        //         arr2.push_back(nums[l]);
        //     }
        // }
        // int i=0;
        // int j=0;
        // while(i<arr1.size() && j<arr2.size()){
        //     ans.push_back(arr1[i]);
        //     ans.push_back(arr2[j]);
        //     i++;
        //     j++;

        // }
        
        // return ans ;

        //method 2 
        int n = nums.size() ;
        vector<int>ans(n);

        int posidx = 0 ;
        int negidx = 1 ;
        for(int i =0; i<n;i++){
            if(nums[i]>0 && posidx < n){
                ans[posidx]= nums[i] ;
                posidx = posidx + 2 ;
            }
            else{
                if(negidx <n){
                    ans[negidx] = nums[i] ;
                    negidx = negidx + 2 ;
                }
                
            }
        }

        return ans ;




    }
};
