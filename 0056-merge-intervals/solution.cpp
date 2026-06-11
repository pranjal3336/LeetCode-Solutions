class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans ;
        int n = intervals.size() ;
        sort(intervals.begin() , intervals.end()) ;//sabse phle end value  ke  according sort kr rhe hai 

        if(intervals.size() == 1){
            ans.push_back({intervals[0]}) ;
            return ans ;
            
        }


       vector<int>temp = intervals[0] ; // ek pair yaani ek vector le rhe hai jo 0th row ke equal hogi 
       for(int i = 1 ; i<n ; i++){
            //overlapping 
            if(temp[1]>=intervals[i][0]){//agr jo pair liya uska end time ith interval ke start time se jyada hoga toh mtlb overlapping hai and hum pair ki end value change kr denge means expand kr denge pair wala interval joki max hoga interval and pair ke end time ka and start ko nhi change krenge voh already minimum hoga kyonki humne sort kr diya hai 
                temp[1] = max(temp[1] , intervals[i][1]) ;
            }
            //no overlapping 
            else{//ab next intervals ko temp ki upadted end value se compare krenge jo ki else case kr rha hai and else case tbhi aayenge jab no overlapping and ab hum jo temp mai value thi usse ans mai push kr denge and ith interval wali row  hi  temp ki new  value bn jaaygi 
                ans.push_back(temp) ;
                temp = intervals[i] ;
            }
       }

       ans.push_back(temp) ; // jab loop khtm ho jayga toh temp mai ek last value hogi jo sabse last mai update hui hogi usse bhi ans mai push krenge 

       return ans ;


    }
};
