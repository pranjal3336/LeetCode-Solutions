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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>ans ;
        if(head == NULL){
            return head ;
        }
        ListNode* temp = head ;
        while(temp!=NULL){
            ans.push_back(temp -> val);
            temp = temp -> next ;
        }

        int i =0 ;
        int j = ans.size()-1 ;
        k = k% ans.size();
        while(i<=j){
            swap(ans[i] , ans[j]) ;
            i++ ;
            j-- ;
        }
        i =0 ;
        j = k-1 ;

        while(i<=j){
            swap(ans[i] , ans[j]) ;
            i++ ;
            j--;
        }
        i =k ;
        j = ans.size()-1 ;
        while(i<=j){
            swap(ans[i] , ans[j]) ;
            i++ ;
            j-- ;
        }

        ListNode* first = new ListNode(ans[0]);
        ListNode* temp1 = first ;
        int x = 1 ;
        while(x<ans.size()){
            ListNode* curr = new ListNode(ans[x]) ;
            temp1 -> next = curr ;
            temp1 = curr ;
            x++ ;
        }

        return first ;

    }
};
