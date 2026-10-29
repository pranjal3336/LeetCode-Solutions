class Solution {
public:
    bool isPowerOfTwo(int n) {
       // return (__builtin_popcountll(n) == 1) ;

       return n>0 && ((n&(n-1)) == 0) ;
    }
};
