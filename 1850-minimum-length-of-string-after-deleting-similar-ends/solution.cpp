class Solution {
public:
    int minimumLength(string s) {
        // int n = s.length() ;
        // int i =0 ;
        // int j = n -1 ;
        // while(i<j){
        //     if(s[i] == s[j]){
        //         int l = i ;
        //         int r = j ;
        //         while(i+1 != j && s[i] == s[i+1]){//jitna bda prefix le skte h lenge 
        //             i++ ;
        //         }
        //         l = i - l +1 ;
        //         while(i+1 != j && s[j] == s[j-1]){//jitna bda suffix le skte h lenge 
        //             j-- ;
        //         }
        //         r = r - j + 1 ;
        //         n = n - (l+r) ;//i n mai se prefix and suffix ki length hta rhe ha
        //         i++ ;
        //         j-- ;
        //     }
        //     else{//jab match nhi hue toh aage check hi nhi krenge seedha j-i+1 length ki string hi answer hoga 
        //         return j-i+1 ;
        //     }
            
             
        // }
        // return n ;

        //above code ko aur optimize kr skte hai 
        int n = s.length() ;
        int i =0 ;
        int j = n -1 ;

        while(i<j && s[i] == s[j]){
            char ch = s[i] ;
            while(i<=j &&  s[i] == ch){// Jitna bada prefix match ho raha hai, usko skip karo
                i++ ;
            }
            while(i<=j && s[j] == ch){// Jitna bada suffix match ho raha hai, usko skip karo
                j-- ;
            }
        }
        return j-i+1 ;// Bachi hui string ki length
    }
};
