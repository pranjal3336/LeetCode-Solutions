class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g) , end(g)) ;
        sort(begin(s) , end(s)) ;

        int i = g.size() -1 ;
        int j = s.size() - 1 ;
        int cnt = 0 ;
        while(i>=0 && j >= 0){
            if(s[j] >= g[i]){
                i-- ; 
                j-- ;
                cnt++ ;
            }
            else{
                i-- ;
            }
        }

        return cnt ;
    }
};
