class Solution {
public:
    int GardenLastPoint ;
    int solve(int i , int maxEnd , vector<pair<int , int>>&range ,   map<pair<int , int> ,  int >&mp){
        if(i >= range.size()){
            if(maxEnd >= GardenLastPoint){
                return 0 ;
            }
            else{
                return 1e9 ;
            }
        }
        if(range[i].first > maxEnd){
            return 1e9 ;
        }

        if(mp.find({i , maxEnd}) != mp.end()){
            return mp[{i , maxEnd}] ;
        }
        int not_open_tap = solve(i+1 ,  maxEnd , range , mp) ;
        int open_tap = 1 + solve(i+1 , max(maxEnd ,range[i].second) , range , mp) ;

        return mp[{i , maxEnd}] = min(not_open_tap , open_tap) ; 
    }
    int minTaps(int n, vector<int>& ranges) {
        // int m = ranges.size() ;
        // vector<int>start_to_max_point(n+1 , 0) ;

        // for(int i=0 ; i<m ; i++){
        //     int start = max(0 , i - ranges[i]) ;
        //     int end = min(n , i + ranges[i]) ;

        //     start_to_max_point[start] = max(start_to_max_point[start] , end ) ;
        // }
        // int taps = 0 ;
        // int maxEnd = 0 ;
        // int currEnd = 0 ;
        // int i =0 ;
        // while(i<n+1){
        //     if(i>maxEnd){//jab paani nhi mila like i maxend se aage pahuch gya 
        //         return -1  ;
        //     }
        //     if(i>currEnd){//jab tap kholna hai 
        //         taps++ ;
        //         currEnd = maxEnd ;
        //     }
        //     maxEnd = max(maxEnd  ,start_to_max_point[i]) ;
        //     i++ ;
        // }

        // return taps ;

        //method 2 using knapsack 
        GardenLastPoint = n ;
        vector<pair<int , int>>range ;
        map<pair<int , int> ,  int >mp ;

        for(int i=0 ; i<ranges.size() ; i++){
            int start = max(0 , i - ranges[i]) ;
            int end = min(n , i + ranges[i]) ;
            range.push_back({start , end}) ;
        }
        int maxEnd = 0 ;
        sort(begin(range) , end(range)) ;
        int ans = solve(0 , maxEnd , range , mp) ;

        return ans == 1e9 ?-1 :ans ;
    }
};
