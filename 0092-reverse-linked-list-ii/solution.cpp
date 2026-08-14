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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //method 1 using SC O(N) and TC O(N) 
        // vector<int>ans ;

        // while(head != NULL){
        //     ans.push_back(head->val) ;
        //     head = head -> next ;
        // }

        // int i = left - 1 ;
        // int j = right -1 ;
        // while(i<j){
        //     swap(ans[i] , ans[j]) ;
        //     i++ ;
        //     j-- ;
        // }

        // ListNode* temp = new ListNode(ans[0]) ;
        // ListNode* start = temp ;
        // for(int i=1 ; i<ans.size() ; i++){
        //     ListNode* temp1 = new ListNode(ans[i]) ;
        //     start -> next = temp1 ;
        //     start = temp1 ;
        // }
        // return temp ;

        //METHOD 2 YEH OPTIMIZED HAI  
        if(head == NULL || head -> next == NULL){
            return head ;
        }
        // Dummy node banate hain taaki edge cases (jaise left = 1 yaani head change hona) easily handle ho jayein.

        ListNode* dummy = new ListNode(0) ;
        dummy->next = head ;
        ListNode* prev = dummy ;
        // Step 1: 'prev' pointer ko us node par le kar jao jo 'left' position se theek pehle hai.
        for(int i = 1 ; i<left ; i++){
            prev = prev -> next ;
        }
        // 'curr' pointer us pehli node ko point karega jise reverse karna shuru karna hai.
        ListNode* curr = prev -> next ;
        // Step 2: In-place reversal ke liye loop chalate hain (harr iteration mein ek node ko aage shift karte hain)

        for(int i=1 ; i<=right - left ; i++){
            ListNode* temp = prev -> next ;// Temporary pointer jo current sub-list ke starting node ko yaad rakhega
            prev -> next = curr -> next  ;// 'prev' ke next mein agli node ko laate hain
            curr -> next = curr -> next -> next ;// 'curr' ki link ko aage waali node se jod kar bypass karte hain
            prev -> next -> next = temp ;// Isolated node ko wapas sub-list ke shuruat mein insert kar dete hain

        }
        // Dummy node ka next hi hamari final modified linked list ka head hoga.
       
        return dummy->next  ;
    }
};
