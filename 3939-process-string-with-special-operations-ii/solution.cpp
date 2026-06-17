class Solution {
public:
    char processStr(string s, long long k) {
       //brute force approach error degi tle wala 
        // vector<char>finalans ;
        // for(int i =0 ; i<s.length() ; i++){

        //     if(s[i] == '*' ){
        //         if(finalans.size()>0){
        //             finalans.pop_back() ;
        //         }
        //         else{
        //             continue ;
        //         }
                
        //     }

        //     else if(s[i] == '#'){
        //         if(finalans.size() >0){
        //             int m = finalans.size() ;
        //             for(int j = 0 ; j<m; j++){
        //                 finalans.push_back(finalans[j]) ;
        //             }
        //         }
        //         else{
        //             continue ;
        //         }
                
        //     }

        //     else if(s[i] == '%'){
        //         if(finalans.size()>1){
        //             int p = 0 ;
        //             int r = finalans.size() -1 ;
        //             while(p<r){
        //                 swap(finalans[p] , finalans[r]) ;
        //                 p++ ;
        //                 r-- ;
        //             }
        //         }
        //         else{
        //             continue ;
        //         }
                
        //     }

        //     else{
        //         finalans.push_back(s[i]) ;
        //     }

        // }


        // if(finalans.size()>k){
        //     return finalans[k] ;
        // }
        // else{
        //     return '.' ;
        // }

        //method 2 
        // 'm' ko long long lena zaroori hai kyunki k ki value 10^15 tak ja sakti hai
        long long m = 0; 
        
        // STEP 1: Forward Pass (Final length nikalna)
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                m = m * 2; // String duplicate hui, toh length double
            }
            else if(s[i] == '*'){
                // Delete operation. Dhyan rahe length 0 se kam nahi ho sakti!
                m = max(0LL, m - 1); 
            }
            else if(s[i] == '%'){
                // Reverse hone par length same rehti hai, toh kuch add/subtract nahi karna
                continue; 
            }
            else{
                m = m + 1; // Normal alphabet aaya, toh length 1 badh gayi
            }
        }

        // Agar maanga gaya index final length se bada ya barabar hai, toh out of bounds
        if(k >= m) return '.';

        // STEP 2: Backward Pass (Reverse Tracking)
       
       
        for(int i = s.length() - 1; i >= 0; i--){
            
            if(s[i] == '*'){
                // Agar '*' mila matlab delete hua tha. 
                // Toh delete hone se just pehle current length 1 zyada rahi hogi.
                m = m + 1; 
            }
            else if(s[i] == '#'){
                // Agar '#' mila matlab string double hui thi.
                // Toh double hone se just pehle length aadhi (half) rahi hogi.
                m = m / 2; 
                
                // Ab check karo, kya mera target index (k) naye (duplicate) half mein tha?
                // Agar 'k' aadhi length (m) se bada ya barabar hai, toh usko minus karke 
                // original (left) half mein wapas le aao.
                if(k >= m){
                    k = k - m; 
                }
            }
            else if(s[i] == '%'){
                // Agar '%' mila toh string reverse hui thi.
                // Reverse hone se pehle index apni mirror position par raha hoga.
                k = m - 1 - k; 
            }
            else{
                // Agar normal alphabet mila, matlab wo is step par append hua tha.
                // Toh iske append hone se pehle length 1 kam rahi hogi.
                m = m - 1; 
                
                // BINGO MOMENT: Agar append hone ke baad ki jagah (m) aur 
                // humara target index (k) match kar gaye, matlab YAHI WO CHARACTER HAI!
                if(k == m){
                    return s[i]; 
                }
            }
        }

        return '.';

        
                

    }
};
