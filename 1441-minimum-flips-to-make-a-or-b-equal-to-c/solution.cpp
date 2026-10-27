class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int flips = 0 ;
        // while(a != 0 || b!= 0 || c != 0){
        //     if((c & 1) == 1){//MSB yaani right most bit agr 1 hai tb a ya b ki last mai agr dono 0 hui thi flips+1 hog vrna ek bhi 1 hota toh 1 or 0 = 1 hota hai 
        //         if((a & 1) == 0 && (b & 1) == 0){
        //             flips++ ;
        //         }
        //     }
        //     else{//agr LSB 0 hua tb 0 or 0 = 0 hi hota hai toh a and b mai se koi bhi last bit 1 hui toh flips+1 krna hoga 
        //         if((a & 1) == 1){
        //             flips++ ;
        //         }
        //         if((b & 1) == 1){
        //             flips++ ;
        //         }
        //     }
        //     a >>= 1 ;//right shift kr rhe hai jaise 101 tha toh hum last bit check chuke hai toh ab 0 wali bit dekhni hai 101 ko >>=1 krne pr 10 chega 
        //     b >>= 1 ;
        //     c >>= 1 ;
        // }

        // return flips ;

        int x = ((a|b)^c) ;
        int y = x&(a&b) ;

        return __builtin_popcount(x) + __builtin_popcount(y) ;
        

    }
};
