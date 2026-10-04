class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size() ;
        vector<int>temp ;
        for(int i =0 ;i<n ; i++){
            temp.push_back(capacity[i] - rocks[i]) ;
        }

        sort(temp.begin() , temp.end()) ;
        int i =0 ;
        while(i < n && additionalRocks >= temp[i]){
            additionalRocks -= temp[i] ;
            i++ ;
        }
        return i ;
    }
};
