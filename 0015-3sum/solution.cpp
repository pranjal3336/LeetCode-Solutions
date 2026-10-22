class Solution {
public:
    vector<vector<int>>ans ;
    void solve(vector<int>& nums , int s , int e , int tar){
        while(s<e){
            if(nums[s] + nums[e] > tar){
                e-- ;
            }
            else if(nums[s] + nums[e] < tar){
                s++ ;
            }
            else{
                while( s < e && nums[s] == nums[s+1]){
                    s++ ;
                }
                while(s < e && nums[e] == nums[e-1]){
                    e-- ;
                }

                ans.push_back({-tar , nums[s] , nums[e]}) ;
                s++ ;
                e-- ;
                
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        
        sort(begin(nums) , end(nums)) ;
        if(n <3){
            return {} ;
        }
        for(int i =0 ; i<n-2 ; i++){

            if( i> 0 && nums[i] == nums[i-1]){
                continue ;
            }

            int n1 = nums[i] ;
            int tar = -n1 ;
            solve(nums , i+1 , n-1 , tar) ;
            
        }

        return ans ;
    }
};
