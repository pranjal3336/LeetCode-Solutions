class Solution {
public:
    bool static cmp(int a , int b){
        if(__builtin_popcountll(a) < __builtin_popcountll(b)){
            return __builtin_popcountll(a) < __builtin_popcountll(b)  ;
        }
        else if(__builtin_popcountll(a) == __builtin_popcountll(b)){
            return a < b ;
        }

        return false ;
        
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin() , arr.end() , cmp) ;
        return arr ;
    }
};
