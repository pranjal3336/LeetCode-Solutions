class Solution {
private:

bool possible(vector<int>& nums, int k , int&mid ){
      int integerCount = 1;
      int splitSum =0;
      
          for(int j=0;j<nums.size();j++){
                  if(splitSum+nums[j]<=mid){
                      splitSum+=nums[j] ;
                  }
                  else{
                      integerCount++;
                      if(integerCount>k || nums[j]>mid){
                          return false ;
                      }
                      splitSum = nums[j];
                  }
          }
          return true ;
  }
  


public:
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        int e=sum ;
        int mid = (s+e)/2 ;
        int ans =-1 ;
        
        if(k>nums.size()){
            return -1 ;
        }
        
        while(s<=e){
            if(possible(nums ,  k , mid)){
                ans = mid ;
                e = mid -1 ;
            }
            else{
                s = mid + 1;
                
            }
            
            mid = (s+e)/2 ;
        }
        return ans ;
    }
};
