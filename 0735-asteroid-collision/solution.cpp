class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st ;
        int n = asteroids.size() ;
        for(int i= 0 ; i<n ; i++){
            int curr = asteroids[i] ;
            bool destroyed = false ;
            while(!st.empty() && st.top() >0 && curr <0){
                int sum = st.top() + curr ;
                if(sum > 0){
                    destroyed =true ;
                    break ;
                    
                }
                else if(sum <0){//yaani left mai destroy krte jaa rhe hai jab tk top >0 and curr <0 hai 
                    st.pop() ;
                }
                else{//sum 0 ho gya yaani sab khtm ab next element pr jaayenge array ke  
                    destroyed =true ;
                    st.pop() ;
                    break ;
                }
            }

        
            if(destroyed == false){
                st.push(curr) ;
            }
            
            
            
        }

        int m = st.size() ;
        vector<int>ans(m) ;
        int i = m-1 ;
        while(!st.empty()){
            ans[i] = st.top() ;
            st.pop() ;
            i-- ;
        }
        return ans ;
    }
};
