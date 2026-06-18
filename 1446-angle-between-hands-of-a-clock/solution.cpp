class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double a =(double(minutes)/60) * 30 ;
        double remaining = 30 - a ;

        double b = (double)minutes - ((hour + 1 )%12)* 5 ;

        double c = b * 6 ;

        double ans = c + remaining ;
        if(ans <0){
            ans = ans *(-1) ;
        }
        return min(ans , double(360) - ans)  ;
        
    }
};
