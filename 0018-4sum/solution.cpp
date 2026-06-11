class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // //brute force TC O(N4 X LogM) where M is quadruples ans SC O(M)+O(N)  //m for st and n for temp worst size 
        // int n = nums.size() ;
        // set<vector<int>>st ;
        // for(int i =0 ; i<n-3 ; i++){
        //     for(int j = i+1 ; j<n-2 ; j++){
        //         for(int k = j+1 ; k<n-1 ; k++){
        //             for(int m = k+1 ; m<n ; m++){
        //                 if((long long)nums[i]+nums[j]+nums[k]+nums[m] == target){
        //                     vector<int>temp = {nums[i],nums[j],nums[k],nums[m]} ;
        //                     sort(temp.begin() , temp.end()) ;
        //                     st.insert(temp) ;
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans(st.begin() , st.end()) ;
        // return ans ;

        //method 2 optimal approach yeh vohi 3sum wali ki trh hai bas yha 2 point fix krenge and 2 pointer move krenge 
        int n = nums.size() ;
        vector<vector<int>>ans ;
        sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue ;
            }

            for(int j = i+1 ; j<n ; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue ;
                }

                int k = j+1 ;
                int l = n-1 ;
                while(k<l){
                        long long sum = nums[i]+nums[j] ;
                        sum+= nums[k] ;
                        sum+= nums[l] ;
                        if(sum <target){
                            k++ ;
                        }

                        else if(sum >target){
                            l-- ;
                        }

                        else{
                            vector<int>temp = {nums[i] , nums[j] , nums[k] , nums[l]} ;
                            ans.push_back(temp) ;
                            k++ ;
                            l-- ;

                            while(k<l && nums[k] == nums[k-1]){
                                k++ ;
                            }

                            while(k<l && nums[l] == nums[l+1]){
                                l-- ;
                            }

                        }


                    }
                }
            }
        

        return ans ;

       


    }
};
