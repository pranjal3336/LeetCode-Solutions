class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0 ;
        // vector<string>substring ;
        // for(int i=0 ; i<word.length();i++){
        //     string temp = "" ;
        //     for(int j = i ; j<word.length() ; j++){
        //         temp+=word[j] ;
        //         substring.push_back(temp) ;

        //     }
        // }

        // for(int i=0 ; i<patterns.size() ; i++){
        //     for(int j =0 ; j<substring.size() ; j++){
        //         if(patterns[i] == substring[j]){
        //             cnt++ ;
        //             break ;
        //         }
        //     }
        // }

        // return cnt ;

        //optimal approach 
        for(int i=0 ; i<patterns.size() ; i++){
            if(word.find(patterns[i]) != string::npos){
                cnt++ ;
            }
        }

        return cnt ;
    }
};
