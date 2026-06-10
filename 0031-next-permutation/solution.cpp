class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //method 1 --> brute force mai agr hum saare permutation print krenge using recursion toh TC O(N! X N) ho jaaygi beacuse N! combination and N depath tk traverse krna hoga and SC(N!) hogi phir traverse krke next permutation print krenge but yeh method bekar hai 
        //method 2 using stl inbuilt function 
        //next_permutation(nums.begin() , nums.end()) ;

        //par hume yeh inbuilt function implement krenge in optimal waay 
        //step 1 breaking point 
        int index = -1 ; //breaking point index 
        int n = nums.size() ;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                index = i ; 
                break ;
            }
        }

       if(index == -1){
        reverse(nums.begin() , nums.end()) ;
        return ;
       }

        //step 2 ab swap krne right se jo just bda hoga breaking wale se 
        for(int i = n-1 ; i>=index+1 ; i--){
            if(nums[i] > nums[index]){
                swap(nums[i] , nums[index]) ;
                break ;
            }
        }

        //step 3 sort krenge ab right part jo bccha hai taaki smallest combination bn ske 
        sort(nums.begin()+index+1 , nums.end()) ;

        
    }
};
