class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int>mp ;
        for(int i =0 ; i<text.length();i++){
            if(text[i] =='b' ||text[i] =='a'|| text[i] =='l'||text[i] =='o'||text[i] =='n' ){
                mp[text[i]]++ ;
            }
            
        }
        // int ans = 0 ;
        int x = mp['l']/2 ;
        int y = mp['o']/2 ;
        int z = min(x , y ) ;
        int ans = min(mp['b'] , min(mp['a'] , min(mp['n'] , z))) ;

        return ans ;
    }
};
