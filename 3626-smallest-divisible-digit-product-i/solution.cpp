class Solution {
public:
    int findproduct(int n){
        int product = 1 ;
        while(n>0){
            product = product*(n%10) ;
            n = n/10 ;
        }

        return product ;
    }
    int smallestNumber(int n, int t) {
        //hum given n se maximum 10 numbers aage tk dekhenge kyonki jaise n mai 1 add krte jaayenge khi na khi digit mai 0 aayga like agr n = 21 hota toh 9 aage jaate jaate 30 aata hai 0 aagya product = 3* 0 = 0 and 0 har t se divisble hoga 
        for(int i= n ; i<= n + 10 ; i++){
            if(findproduct(i) %t == 0){
                return i ;
            }
        }

        return -1 ;
    }
};
