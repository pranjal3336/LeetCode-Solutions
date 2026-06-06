class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //TC O(N2) and SC(1) ;
        // int ans = 0 ;
       
        int n = nums.size() ;
        // for(int i = 0 ; i<n ; i++){
        //     int sum =0 ;
        //     for(int j = i ; j<n ; j++){
        //         sum +=nums[j];
        //         if(sum == k){
        //             ans+=1 ;
        //         }
        //     }
        // }
        // return ans ;

        //now using prefix sum with hash map 

        // vector<int>prefixSum(n , 0) ;
        // prefixSum[0] = nums[0] ;
        
        // for(int i =1 ; i<n ; i++){
        //     prefixSum[i] = prefixSum[i-1] + nums[i] ;
        // }

        int prefixSum = 0 ;//hume prefixsum wala array bnane ki jrurat nhi hai hum saath hi track kr skte hai add krke 

        int count = 0 ;

        unordered_map<int , int>m ;//yeh prefix sum wale values ki frequency store krega 
        for(int j = 0 ; j<n ; j++){
            prefixSum+=nums[j] ;
            if(prefixSum == k){//prefixSum is sum till index j 
                count++ ;
            }
            int val = prefixSum - k ;//val ko current sum bhi kh skte hai 
            if(m.find(val) != m.end()){
                count += m[val] ;
            }

           m[prefixSum]++ ;//agr value mile ya naa mile uski frequncy increment hogi chahe create krke phle 0 hogi phir 1 ho jaygi , agr alraedy hai toh direct increment hogi 
        }

        return count ;
    }
};
