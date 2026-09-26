class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>temp(26,0) ;
        int n = s.length() ;
        for(int i=0 ; i<n ; i++){
            temp[s[i] - 'a'] = i ;
        }

        int i = 0 ;
        vector<int>ans ;
        int end  ;
        while(i<n){
            int j = i ;
            end = temp[s[i]-'a'] ;
            while(j<end){
                end = max(end , temp[s[j] - 'a']) ;
                j++ ;
            }
            ans.push_back(j-i+1) ;
            i=j+1 ;
        }
        return ans ;

    }
};
