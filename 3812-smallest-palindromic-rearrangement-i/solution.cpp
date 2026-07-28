class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length() ;
        int half = n/2 ;

        string temp = s.substr(0 , half) ;
        sort(temp.begin() , temp.end()) ;

        string ans = "" ;
        //ans.reserve(n) ;
        ans+=temp ;

        if(n%2 != 0){
            ans += s[half] ;
        }
        ans.append(temp.rbegin(), temp.rend()); // Reverse mirror part in-place yaani reverse(temp.begin() ,temp.end()) ki jgh ans mai inplace reverse part add kr rhe hai kyunki humne n length ans mai reserve kr li thi 
        
        return ans;
    }
};
