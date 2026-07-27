
class Solution {
public:

    vector<int>nextSmaller(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        for(int i= n-1 ; i>=0 ; i--){
            if(st.empty()){
                ans[i] = n ;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop() ;
                }

                ans[i] = st.empty() ? n : st.top() ;
            }
            st.push(i) ;

        }
        return ans ;
    }

    vector<int>prevSmaller(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        for(int i= 0 ; i<n ; i++){
            if(st.empty()){
                ans[i] = -1 ;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){//yeh = upr wale function ya isme se khi bhi aa skta tha kynki yeh duplicate subarray ko add krne se rokega 
                    st.pop() ;
                }

                ans[i] = st.empty() ? -1 : st.top() ;
                
            }
            st.push(i) ;

        }
        return ans ;
    }
    int sumSubarrayMins(vector<int>& arr) {
        //method 1 using brute force 
        // int ans = 0 ;
        // int mod = 1e9+7 ;
        // int n = arr.size() ;
        // for(int i=0 ; i<n ; i++){
        //     int mini = arr[i] ;
        //     for(int j=i ; j<n ; j++){
        //         mini = min(mini , arr[j]) ;
        //         ans= ((ans%mod) + (mini%mod))%mod ;
        //     }
            
        // }
        // return ans%mod ;

        //method 2 using stack and next and previous smaller element concept 
        int n = arr.size() ;
        int mod  = 1e9 + 7 ;

        vector<int>next = nextSmaller(arr , n) ;
        vector<int>prev = prevSmaller(arr ,n) ;

        long long  ans = 0 ;
        for(int i=0 ; i<n ; i++){
            long long left = i - prev[i] ;//left mai kitne small elements hai current arr[i] se 
            long long  right = next[i] - i ;//right mai kitne small elements hai current arr[i] se 

            long long count = (left*right)%mod  ; //total kitne subarray bne current yaani arr[i] ko as a minimum element maan kr 
            long long contribution = (arr[i]*count)%mod ; //arr[i] ke jitne subarray aaye unme arr[i] minimum tha toh uska sum nikal rhe hai 
            ans = (ans +contribution)%mod ;//ans mai add kr rhe hai har element ka contribution 
        }

        return ans ;
    }
};
