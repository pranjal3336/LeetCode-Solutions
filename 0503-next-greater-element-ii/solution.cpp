class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        // Final answer array jisme pehle se hi -1 bhara hua hai. 
        // Agar kisi ka next greater nahi mila, toh -1 hi rahega.
        vector<int> ans(n, -1); 
        stack<int> st;

        // Array circular hai, isliye loop ko double (2*n) time chala rahe hain right-to-left.
        // i = 2*n - 1 se start kiya taaki imaginary second array ko bhi cover kar lein.
        for (int i = 2 * n - 1; i >= 0; i--) {
            
            // i % n karne se hum bina extra space banaye, array ko circular form mein access kar lete hain.
            int curr = nums[i % n]; 

            // MONOTONIC STACK LOGIC: 
            // Agar stack ke top par current number se chota (ya equal) element hai, 
            // toh usko pop kardo. Kyunki left side aane wale numbers ke liye 
            // ab 'curr' hi next greater banega, un chote elements ka koi kaam nahi.
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // Sirf original array (jab i < n ho) ke elements ka answer save karna hai.
            // Kyunki i >= n wala hissa toh bas right side ke greater elements dhoondhne ke liye (as a backup) tha.
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }

            // Current element ko stack mein daal do, taaki left wale numbers 
            // isko apne 'next greater' ki tarah use kar sakein.
            st.push(curr); 
        }

        return ans;
        
    }
};
