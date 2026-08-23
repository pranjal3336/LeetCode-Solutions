class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x>0 && x%10 == 0)){//negative yaa aese number jo 0 se bde ho and jinke end mai 0 aata hai voh palindrome nhi ho skte 
            return false ;
        }
        // string a = to_string(x) ;

        // int i = 0 ;
        // int j = a.length() -1 ;
        // bool ans = true ;
        // while(i<j){
        //     if(a[i] != a[j]){
        //         return false ;
        //     }
        //     i++ ;
        //     j-- ;
        // }
        // return ans ;

        int a = 0 ;
        while(x> a){
            int last = x%10 ;
            a = a*10 + last ;
            x = x/10 ;
        }

        if(x == a || x == a/10 ){//even length of integer 
            return true ;
        }
        // else if(){//odd length of integer 
        //     return true ;
        // }
        return false ;

    }
};
