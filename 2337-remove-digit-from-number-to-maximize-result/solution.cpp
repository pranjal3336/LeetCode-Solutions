class Solution {
public:
    string removeDigit(string number, char digit) {
        // string maxResult = "" ;
        // // Step 1: Poori string par iterate karo
        // for (int i = 0; i < number.length(); i++) {
            
        //     // Step 2: Jab bhi target 'digit' mile
        //     if (number[i] == digit) {
                
        //         // Index i wale character ko skip karke naye parts ko jodo:
        //         // substr(0, i)   -> index 0 se leker (i - 1) tak
        //         // substr(i + 1) -> index (i + 1) se end tak
        //         string temp = number.substr(0, i) + number.substr(i + 1);
                
        //         // Step 3: Check karo ki yeh new result pichle waale se bada hai kya
        //         maxResult = max(maxResult, temp);
        //     }
        // }
        
        // // Step 4: Max string return kar do
        // return maxResult;

        //method 2 
        int n = number.length() ;
        int lastOccurrence = -1 ;// Last position of 'digit' save karne ke liye

        for(int i=0 ; i<n ; i++){
            if(number[i] == digit){
                lastOccurrence = i ;// Last seen index update kar do

                // Rule 1: Agar agla character bada hai, toh isi digit ko hata do
                if(i+1 <n && number[i] < number[i+1]){
                    return number.substr(0 , i) + number.substr(i+1) ;
                }
            }
        }
        // Rule 2: Agar kisi digit ke baad bada character nahi mila,
        // toh last occurrence wale digit ko hata do.
        return number.substr(0 , lastOccurrence) + number.substr(lastOccurrence+1) ;
    }
};
