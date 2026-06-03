class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n , 1) ;
        vector<int>hash(n) ;
        //take example arr = [5,4,11,16,8] then dp array will be 
        //dp = [1,1,2,3,2] and LIS length 3 aayi hai joki index 3 pr hai yaani LIS ka last element index 3 yaani 16 hoga 
        int maxi = 1 ;
        int lastindex = 0 ;
        sort(nums.begin() , nums.end()) ;
        for(int i =0 ; i<n ; i++){
            hash[i] = i ;
            for(int prev = 0 ; prev<i ; prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev] ;
                    hash[i] = prev ;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i] ;
                lastindex = i ;//yeh btayga ki lis ki value konse index pr pdi hai dp vector mai 
            }
        }
        
        vector<int>temp ;
        temp.push_back(nums[lastindex]) ;//humne temp mai lis ka last element push kr diya hai yaan 16 ab bas hume hash vector ka use krke element store krnne hai 
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex] ;
            temp.push_back(nums[lastindex]) ;//yeh sab reverse mai aaye honge inhe dubara reverse krna hoga 
            
        }
        
        reverse(temp.begin() , temp.end()) ;
        return temp ;
    }
};
