class Solution {
public:
    bool static cmp(int &a , int &b){
        if(__builtin_popcount(a) < __builtin_popcount(b)){
            return __builtin_popcount(a) < __builtin_popcount(b)  ;
        }
        else if(__builtin_popcount(a) == __builtin_popcount(b)){
            return a < b ;
        }

        return false ;
        
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , cmp) ;
        return arr ;
    }
};
