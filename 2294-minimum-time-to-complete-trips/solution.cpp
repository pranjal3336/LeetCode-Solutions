class Solution {
public:
    long long  trips(long long  t ,vector<int>& time ){
        long long  ans = 0 ;
        for(int i =0 ; i<time.size() ; i++){
            ans += t/time[i] ;
        }
        return ans ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long  l = 1 ;
        long long r = (long long)totalTrips*(long long)(*min_element(begin(time) , end(time))) ;

        while(l<r){
            long long  mid = l+(r-l)/2 ;

            if(trips(mid , time) >= totalTrips){
                r = mid ;
            }
            else{
                l = mid +1;
            }
        }
        return l ;
    }
};
