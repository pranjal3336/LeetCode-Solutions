/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        //method 1 using vector
        // vector<int>ans ;
        // while(head != NULL){
        //     ans.push_back(head->val) ;
        //     head = head -> next ;
        // }

        // int i =0 ; 
        // int j = ans.size() -1 ;
        // int sum = 0 ;
        // while(i<j){
        //     int temp = ans[i]+ ans[j] ;
        //     sum = max(sum , temp) ;
        //     i++ ;
        //     j-- ;
        // }
        // return sum ;

        //method 2 using stack 
       
        stack<int>st ;
        ListNode* curr = head ;
        while(curr!=NULL){
            st.push(curr->val) ;
            curr = curr -> next ;
        
        }

        int sum = 0 ;
        int N = st.size() ;
        curr = head ;
        int i = 1 ;
        while(i<=N/2){
           
            sum = max(sum , curr->val + st.top() ) ;
            curr = curr -> next ;
            st.pop() ;
            i++ ;

        }
        return sum ;

    }
};
