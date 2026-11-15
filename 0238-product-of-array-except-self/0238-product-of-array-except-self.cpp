class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //method 1 -->//TC O(N) and SC O(N)
        // int n = nums.size() ;
        // vector<int>prefix(n) ;//left side ka product store krega 
        //  vector<int>suffix(n) ;//right side ka product store krega 
        // prefix[0] = 1 ;
        // suffix[n-1] =  1 ;

        // for(int i =1 ; i<n ; i++){
        //     prefix[i] = nums[i-1]*prefix[i-1] ;
        // }

        // for(int i =n-2 ; i>=0 ; i--){
        //     suffix[i] = nums[i+1]*suffix[i+1] ;
        // }

        // vector<int>ans(n) ;
    

        // for(int i=0 ; i<n ; i++){
        //     ans[i] = prefix[i]*suffix[i] ;
        // }
        // return ans ;

        //method 2 --> same code use krenge bs extra space nhi lenge ans array bnaenge usse hi modify krenge phle prefix bna denge isse then baad mai final answer bna denge ek RP varibale se multiply krte krte yeh varibale right yaani suffix product store krega 

        int n = nums.size() ;
        vector<int>ans(n) ;
        ans[0] = 1 ;

        for(int i =1 ; i<n ; i++){
            ans[i] = nums[i-1]*ans[i-1] ;
        }

        int RP = 1 ;
        for(int i = n-1 ; i>=0 ; i--){
            ans[i] = ans[i]*RP ;
            RP = RP*nums[i] ;
        }

    
        return ans ;
    }
};