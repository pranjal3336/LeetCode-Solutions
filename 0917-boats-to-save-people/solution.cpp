class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people)  , end(people)) ;
        int n = people.size() ;

        int ans = 0 ;
        int i = 0 ;
        int j = n-1 ;

        while(i<=j){
            if(people[i] + people[j] <= limit){
                ans++ ;
                i++ ;
                j-- ;
            }
            else{
                ans++ ;
                j-- ;
            }
        }
        return ans ;
    }
};
