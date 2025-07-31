/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA ;
        ListNode* ans = NULL ;

        while(temp1!=NULL){
            for(ListNode* temp2 = headB ; temp2!=NULL ; temp2 = temp2 -> next ){
                if(temp1 == temp2){
                    ans = temp1 ;
                    return ans ;
                }

            }
            temp1 = temp1 -> next ;
        }
        return ans ;



        
    }
};
