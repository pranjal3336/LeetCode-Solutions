class Solution {
public:
    int canEat(int hr , vector<int>&piles){
        int ans = 0 ;
        for(int i =0 ; i<piles.size() ; i++){
            ans += ceil(piles[i]/(double)hr) ;
        }

        return ans ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1 ;
        int r = *max_element(begin(piles) , end(piles)) ;

        while(l<r){
            int mid = l + (r-l)/2 ;

            if(canEat(mid , piles) <=h){
                r = mid ;
            }
            else{
                l = mid+1 ;
            }
        }

        return r ;
    }
};
