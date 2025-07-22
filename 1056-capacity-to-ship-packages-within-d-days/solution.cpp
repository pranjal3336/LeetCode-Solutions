class Solution {
private:
bool possible(vector<int>& weights, int days, int& mid ){
      int dayCount = 1;
      int weightSum =0;
      
          for(int j=0;j<weights.size();j++){
                  if(weightSum+weights[j]<=mid){
                      weightSum+=weights[j] ;
                  }
                  else{
                      dayCount++;
                      if(dayCount>days || weights[j]>mid){
                          return false ;
                      }
                      weightSum = weights[j];
                  }
          }
          return true ;
  }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        
        int e=sum ;
        int mid = (s+e)/2 ;
        int ans =-1 ;
        
        if(days>weights.size()){
            return -1 ;
        }
        
        while(s<=e){
            if(possible(weights ,  days , mid)){
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
