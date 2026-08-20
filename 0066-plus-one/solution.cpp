class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size() ;
        for(int i=n-1 ; i>=0 ; i--){
            // Agar digit 9 nahi hai, toh 1 add karo aur return kar do
            if(digits[i]<9){
                digits[i]++ ;
                return digits ;
            }
           // Agar digit 9 hai, toh wo 0 ban jayega aur carry aage jayega
            digits[i] = 0 ;
        }
        // Agar saare digits 9 the (jaise 999 -> 1000), toh aage 1 add karna padega
        digits.insert(digits.begin() , 1) ;
        return digits ;
    }
};
