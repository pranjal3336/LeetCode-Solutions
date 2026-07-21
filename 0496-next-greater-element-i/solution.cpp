class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>mp ;//nums2 ke element ko unke next greater se map krega 
        stack<int>st ;
        
        for(int i=nums2.size()-1 ; i>=0 ; i--){
            int curr = nums2[i] ;
            while(!st.empty() && st.top()<= curr){//stack se jb tk pop krenge jab tk ki top ka element curr se bda naa aa jaaye 
                st.pop() ;
            }
            if(st.empty()){//agr stack empty ho gya toh koi bda nhi mila ans mai -1 daal denge 
                mp[nums2[i]] = -1 ;
            }else{//mil, gya toh st.top daal denge 
                mp[nums2[i]] = st.top() ;
            }
            st.push(curr) ;
        }

        // nums1 ke elements ki value seedhe map se lookup kar lo O(1) me
        vector<int>final(nums1.size()) ;
        for(int i=0 ; i<nums1.size() ; i++){
            final[i] = mp[nums1[i]] ;
        }
        
        return final ;


    }
};
