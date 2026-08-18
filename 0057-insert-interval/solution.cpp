class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() ;
        vector<vector<int>>ans ;

        int i =0 ;
        while(i<n && intervals[i][1] < newInterval[0]){//no overlapping
            ans.push_back(intervals[i]) ;
            i++ ;
        }

        while(i<n && intervals[i][0] <= newInterval[1]){//overlapping

            newInterval[0] = min(intervals[i][0] , newInterval[0]) ;
            newInterval[1] = max(intervals[i][1] , newInterval[1]) ;

            i++ ;
        }

        ans.push_back(newInterval) ;//new interval insert kra 

        while(i<n){//no overlapping
            ans.push_back(intervals[i]) ;
            i++ ;
        }

        return ans ;
    }
};
