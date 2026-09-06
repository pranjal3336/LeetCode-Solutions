class Solution {
public:
    string reorganizeString(string s) {
        vector<int>temp(26 , 0) ;
        for(char ch : s){
            temp[ch -'a']++ ;
        }

        int sum = accumulate(temp.begin() , temp.end() , 0) ;
        int maxi = *max_element(temp.begin() , temp.end()) ;
        int others = sum - maxi ;
        if(maxi > others+1){
            return "" ;
        }
        string ans = "" ;
        priority_queue<pair<int , char> , vector<pair<int , char>>>pq ;
        for(int i =0 ; i<temp.size() ; i++){
            if(temp[i] != 0){
                pq.push({temp[i] , (char)('a' + i)}) ;
            }
        }

        while(!pq.empty() ){
            pair<int, int>a = pq.top() ;
            pq.pop() ;
            ans+=a.second  ;
            
            if(!pq.empty()){
                pair<int, int>b = pq.top() ;
                pq.pop() ;
                if(a.first - 1 != 0){
                    pq.push({a.first -1 , a.second}) ;
                }
                if(b.first - 1 != 0){
                    pq.push({b.first -1 , b.second}) ;
                }
                ans+=b.second  ;
            } 
            
        }

        return ans ;

    }
};
