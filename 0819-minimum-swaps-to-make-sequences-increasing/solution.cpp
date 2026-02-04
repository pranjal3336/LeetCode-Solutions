class Solution {
public:

    //recursion + memoization
    int solve(vector<int>& nums1 , vector<int>& nums2 , int index , bool swapped , vector<vector<int>>&dp){
        //base case 
        if(index == nums1.size()){//humne pta hai nums1 and nums2  ka size same same hai islye humne base case mai sirf nums1 use kr liya agr index array se bahr ho jaaye toh 0 return krenge 
            return 0 ;
        }

        if(dp[index][swapped] != -1){
            return dp[index][swapped] ;
        }

        int ans = INT_MAX ;//starting mai answer ko maximum liya hai 

        //humne do variable liye hai prev1 and prev2 jo nums1 and nums2 ke previous element hai iinka use hoga kyonki jab hume nums1 and nums2 ke ith index wale ko swap krna hoga toh hum actual array mai changes nhi krenge bas hum jo prev1 and prev2 hai unhe swap krenge 
        int prev1 = nums1[index - 1] ;
        int prev2 = nums2[index - 1] ;

        //catch 
        if(swapped){
            swap(prev1 , prev2) ;//agr swapped 1 ho jayga mtlb swap wali call gyi hogi jisse swapped 1 ho chuka hoga and hum ans mai +1 toh kr denge p prev1 and prev2 ko swap kr denge kyonki hum actual array mai changes nhi kr rhe 
        }

        //no swap --> agr nums1 and nums2 dono ko index wali element previous wali se bda hai toh swap nhi krenge 
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(nums1 , nums2 , index+1 , 0 , dp) ;
        }

        //swap wala case 
        if(nums1[index] > prev2 && nums2[index] > prev1){// yha pr trick hai kyonki swap jbhi krenge tb nums1 ka element  nums2 ke previous yani prev2 se bda hoga and nums2 ka element prev1 se bda hoga 
            ans = min(ans , 1+ solve(nums1 , nums2 , index+1 , 1 , dp)) ;
        }

        dp[index][swapped] = ans ; 
        return dp[index][swapped] ;

    }

    //method 2 --> bottom up approach using tabulation 
    int solve1(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0)) ;

        for(int index = n-1 ; index>=1 ; index--){
            for(int swapped = 1 ; swapped>=0 ; swapped--){
                int ans = INT_MAX ;
                int prev1 = nums1[index-1] ;
                int prev2 = nums2[index-1] ;

                if(swapped){
                    swap(prev1 , prev2) ;
                }

                if(nums1[index]>prev1 && nums2[index] > prev2){
                    ans = dp[index+1][0] ;
                    
                }
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans , 1+ dp[index+1][1]) ;
                }

                 dp[index][swapped] = ans ;
            }
           
        }

        return dp[1][0] ;

    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //step 1 humne dono vector mai starting mai -1 insert kra hai 
        nums1.insert(nums1.begin() , -1) ;
        nums2.insert(nums2.begin() , -1) ;

        // int n = nums1.size() ;
        // vector<vector<int>>dp(n , vector<int>(2 , -1)) ; //coulumn 2 hi aayenge kyonki swapped ya toh 0 ya 1 hoga means 2 value hi hai uski

        // bool swapped = 0 ;//humne ek variable liya hai jisse false rkha hai 
        // return solve(nums1 , nums2 , 1 , swapped , dp) ;

        return solve1(nums1 , nums2) ;
    }
};
