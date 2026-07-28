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
    long long sumSubarrayMins(vector<int>& arr) {
       
        //method -> using stack and next and previous smaller element concept 
        int n = arr.size() ;
       

        vector<int>next = nextSmaller(arr , n) ;
        vector<int>prev = prevSmaller(arr ,n) ;

        long long  ans = 0 ;
        for(int i=0 ; i<n ; i++){
            long long left = i - prev[i] ;//left mai kitne small elements hai current arr[i] se 
            long long  right = next[i] - i ;//right mai kitne small elements hai current arr[i] se 

            long long count = (left*right) ; //total kitne subarray bne current yaani arr[i] ko as a minimum element maan kr 
            long long contribution = (1LL * arr[i]*count); //arr[i] ke jitne subarray aaye unme arr[i] minimum tha toh uska sum nikal rhe hai 
            ans = (ans +contribution) ;//ans mai add kr rhe hai har element ka contribution 
        }

        return ans ;
    }

    vector<int>nextGreater(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        for(int i= n-1 ; i>=0 ; i--){
            if(st.empty()){
                ans[i] = n ;
            }
            else{
                while(!st.empty() && arr[st.top()] < arr[i]){
                    st.pop() ;
                }

                ans[i] = st.empty() ? n : st.top() ;
            }
            st.push(i) ;

        }
        return ans ;
    }

    vector<int>prevGreater(vector<int>&arr , int n){
        vector<int>ans(n) ;
        stack<int>st ;
        for(int i= 0 ; i<n ; i++){
            if(st.empty()){
                ans[i] = -1 ;
            }
            else{
                while(!st.empty() && arr[st.top()] <= arr[i]){//yeh = upr wale function ya isme se khi bhi aa skta tha kynki yeh duplicate subarray ko add krne se rokega 
                    st.pop() ;
                }

                ans[i] = st.empty() ? -1 : st.top() ;
                
            }
            st.push(i) ;

        }
        return ans ;
    }
    long long  sumSubarrayMaxs(vector<int>& arr) {
        
        //method -->using stack and next and previous greater element concept 
        int n = arr.size() ;
        

        vector<int>next = nextGreater(arr , n) ;
        vector<int>prev = prevGreater(arr ,n) ;

        long long  ans = 0 ;
        for(int i=0 ; i<n ; i++){
            long long left = i - prev[i] ;//left mai kitne greater elements hai current arr[i] se 
            long long  right = next[i] - i ;//right mai kitne greater elements hai current arr[i] se 

            long long count = (left*right)  ; //total kitne subarray bne current yaani arr[i] ko as a maximum element maan kr 
            long long contribution = (1LL *arr[i]*count); //arr[i] ke jitne subarray aaye unme arr[i] maximum tha toh uska sum nikal rhe hai 
            ans = (ans +contribution) ;//ans mai add kr rhe hai har element ka contribution 
        }

        return ans ;
    }

    long long subArrayRanges(vector<int>& nums) {
        //method 1 using brute force TC O(N2) and SC O(1)
        // long long  sum = 0 ;
        // for(int i= 0 ; i<nums.size() ; i++){
        //     int  maxi = nums[i] ;
        //     int  mini = nums[i] ;

        //     for(int j= i+1 ; j<nums.size() ; j++){//i+1 se loop begin hai beacuse agr j =i se krte toh largets and smallest nums[i] aata jo ki phir unko subtract krne pr 0 aata and sum mai 0 add hota isse sum pr frk nhi pd rha isliye loop i+1 se chla rhe hai
        //         maxi = max(nums[j] , maxi) ;
        //         mini = min( nums[j] , mini) ;
        //         sum = sum + (long long)(maxi - mini) ;
        //     }
        // }

        // return sum ;

        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums) ; //yhe question ek trh se saare largest elmenets in all subarray ka sum - saare smallest elements in all subray ka sum se aayga iska answer kyonki range largets - smallest hoti hai 
    }
};
