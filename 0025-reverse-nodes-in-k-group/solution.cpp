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
private:
int getLength(ListNode* head){
    int len =0;
    while(head!=NULL){
        len++;
        head = head -> next ;
    }
    return len ;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      //base case 
    if(head == NULL || getLength(head)<k){
        return head ;
    }

    //step 1 -> reverse first k nodes 
    ListNode* prev = NULL ;
    ListNode* curr = head ;
    ListNode* next = NULL ;
    int count = 0 ;

    while(  curr!=NULL && count<k){
        next = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = next ;
        count++ ;
    }

    //step 2 -> recursion dekh lega aage ka 
    if( next != NULL){
        head -> next = reverseKGroup(next , k);
    }

    //step 3 -> return head of reverse linked list 
    return prev ;  
    }
};
