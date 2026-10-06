class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = ranges.size() ;

        vector<int>start_to_max_point(n+1 , 0) ;

        for(int i=0 ; i<m ; i++){
            int start = max(0 , i - ranges[i]) ;
            int end = min(n , i + ranges[i]) ;

            start_to_max_point[start] = max(start_to_max_point[start] , end ) ;
        }

        
        int taps = 0 ;
        int maxEnd = 0 ;
        int currEnd = 0 ;
        int i =0 ;
        while(i<n+1){

            if(i>maxEnd){
                return -1  ;
            }

            if(i>currEnd){
                taps++ ;
                currEnd = maxEnd ;
            }

            maxEnd = max(maxEnd  ,start_to_max_point[i]) ;
            i++ ;
        }

        return taps ;
    }
};
