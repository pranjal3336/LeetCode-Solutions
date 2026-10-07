class Solution {
public:
    void computeLPS(vector<int>& pattern , vector<int>&LPS ,int m){
        int len = 0 ;
        LPS[0] = 0 ;

        int i = 1 ;
        while(i<m){
            if(pattern[i] == pattern[len]){
                len++ ;
                LPS[i] = len ;
                i++ ;
            }
            else{
                if(len != 0){
                    len = LPS[len -1] ;
                }
                else{
                    LPS[i] = 0 ;
                    i++ ;
                }
            }
        }
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size() ;
        int n = nums.size() ;
        
        vector<int>arr ;

        for(int i = 1 ; i<n ; i++){
            if(nums[i-1] < nums[i]){
                arr.push_back(1) ;
            }
            else if(nums[i-1] > nums[i]){
                arr.push_back(-1) ;
            }
            else{
                arr.push_back(0) ;
            }
        }


        vector<int>LPS(m , 0) ;

        computeLPS(pattern , LPS , m) ;
        int ans = 0 ;
        int i=0 ;
        int j =0 ;
        
        while(i < arr.size()){
            if(arr[i] == pattern[j]){
                i++;
                j++;

                if(j == m){
                    ans++;
                    j = LPS[j-1];
                }
            }
            else{
                if(j != 0){
                    j = LPS[j-1];
                }
                else{
                    i++;
                }
            }
    }

        return ans ;
    }
};
