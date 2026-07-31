class Solution {
public:
    int minimumPushes(string word) {
        int n =  word.length() ;
        vector<int>arr(26 , 0) ;
        for(int i=0 ; i< n ; i++){
            arr[word[i] - 'a']++ ;
        }

        sort(arr.begin() , arr.end()) ;
        reverse(arr.begin() , arr.end()) ;

        

        int ans = 0 ;
        for(int i = 0 ; i<26 ; i++){
            if (arr[i] == 0) break; // Optimization: agar frequency 0 ho gayi toh aage check karne ki zaroorat nahi kyonki descending mai lgae hai toh agr 0 aaya toh uske baad ki sbki frequency 0 hogi vha traverse krne ki need nhi hai 
            if(i <8){
                ans += arr[i]*1 ;
            }
            else if(i<16){
                ans += arr[i]*2 ;
            }
            else if(i<24){
                ans+=arr[i]*3 ;
            }
            else{
                ans += arr[i]*4 ;
            }
        }

        return ans ;


        

    }
};
