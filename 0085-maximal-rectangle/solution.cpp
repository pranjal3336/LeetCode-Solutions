class Solution {
public:
    vector<int>nextsmaller(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        st.push(-1) ;

        for(int i= n-1 ; i>=0 ; i--){
            int curr = arr[i] ;
            while( st.top() != -1 && arr[st.top()] >= curr){
                st.pop() ;
            }
            ans[i] = st.top() ;
            st.push(i) ;
        }
        return ans ;
    }

    vector<int>prevsmaller(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        st.push(-1) ;

        for(int i= 0 ; i<n ; i++){
            int curr = arr[i] ;
            while( st.top() != -1 && arr[st.top()] >= curr){
                st.pop() ;
            }
            ans[i] = st.top() ;
            st.push(i) ;
        }
        return ans ;
    }

    int largestarea(vector<int>&arr, int n){
        int area = INT_MIN ;
        vector<int>next ; 
        next = nextsmaller(arr , n) ;

        vector<int>prev ; 
        prev = prevsmaller(arr , n) ;


        for(int i=0 ; i<n ; i++){
            int l = arr[i] ;
            if(next[i] == -1){
                next[i] = n ;
            }
            int b = next[i]-prev[i] - 1 ; 

            int newarea = l*b ;
            area= max(area , newarea) ;
        }

        return area ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size() ;
        int n = matrix.size() ;
        int area = INT_MIN ;
       
       vector<int>start(m , 0) ;

       for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(matrix[i][j] == '1'){
                    start[j]++ ;
                }
                else{
                    start[j] = 0 ;
                }
            }
            area = max(area , largestarea(start , m)) ;
       }

       return area ;




        

    }
};
