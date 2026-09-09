class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans ;
        sort(intervals.begin() , intervals.end()) ;
        int n = intervals.size() ;
        vector<int>temp = intervals[0] ;

        for(int i = 1 ; i<n ; i++){
            if(temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1] , intervals[i][1]) ;
            }
            else{//no overlapping
                ans.push_back(temp) ;
                temp = intervals[i] ;
            }
        }
        ans.push_back(temp) ;
        return ans ;
    }
};
