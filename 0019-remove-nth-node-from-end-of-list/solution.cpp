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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || head ->next == NULL){
        return NULL ;
    } 
    // int L = 0 ;
    // ListNode*curr = head ;
    // while(curr != NULL){//total length nikal rha hu 
    //     curr = curr -> next ;
    //     L++ ;
    // }
    // if(L == n){
    //     ListNode* temp = head -> next ;
    //     delete(head) ;
    //     return  temp ;
    // }
    // curr = head ;
    // int k = L - n + 1 ;//nth node from last is L-n+1 node from starting 
    // while(k>2){//k>2 se just nth node from last ke phle node pr aaenge and phir curr ke next   ko curr ke next ke next se link kr denge 
    //     curr = curr->next ; 
    //     k-- ;
    // }
    // //cout << curr ->val ;
    // curr -> next = curr -> next -> next ;
    // return head ;

    //approach 2 using slow and fast ;

    ListNode* fast = head ;

    for(int i=1 ; i<= n ; i++){
        fast = fast -> next ;
    }

    if(fast == NULL){
        ListNode* temp = head -> next ;
        delete(head) ;
        return  temp ;
    }

    ListNode* slow = head ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next ;
    }
    ListNode* delNode = slow->next ;
    slow -> next = slow -> next -> next ;
    delete(delNode) ;
    return head ;


    }
};
