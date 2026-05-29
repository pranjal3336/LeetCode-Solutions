class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        
            return a[1] < b[1] ;

      
    }

    //yeh question n meeting in one room wala hai bas isme hum uss question ka answer nikalenge like ending time <= starting time of next meeting hogi condition and jo iska answer niklega voh maximum meeting hogi and phir answer ko n yaani size of intervals mai se minus kr denge kyonki jo meeting bch gyi vhi ek trh se overlapping interval the 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        int n= intervals.size() ;
        sort(intervals.begin() , intervals.end() , cmp) ;
        int temp = intervals[0][1] ;
        for(int i= 1 ; i<intervals.size() ; i++){
            if(temp <= intervals[i][0]){
                ans++ ;
                 temp =intervals[i][1] ;
               
            }
            
            
        }
        return  n - ans ;

    }
};
