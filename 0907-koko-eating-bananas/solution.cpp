class Solution {
public:
    int canEat(int hr , vector<int>& piles){

        int ans = 0 ;
        for(int i =0 ; i<piles.size() ; i++){
            // ans  = ans + (piles[i] +hr -1)/hr ;
            ans += ceil(piles[i]/(double)hr) ;
        }
        return ans ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1 ;
        int r = *max_element(piles.begin() , piles.end()) ;

        while(l<r){
            int mid = l +(r-l)/2 ;//per hour koko can eat bananas

            if(canEat(mid , piles) <= h){
                r = mid ;
            }
            else{
                l = mid +1 ;
            }
        }
        return l ;
    }
};
