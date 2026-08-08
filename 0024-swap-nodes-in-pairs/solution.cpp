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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head ;
        }
        //A -> B -> C -> D MAI HUM A KO C AND D WALE PART SE JODENGE AND B KO A SE  PR PHLR B KO KHI STORE KRENGE 
        ListNode* temp = head -> next ;//B KO TEMP MAI LE RHE 
        head -> next = swapPairs(head -> next -> next) ;//AB A KO B KE AAGE WALE PART YAANI C AND D SE JOD RHE AND RECURSION UNKO BHI SWAP KRKE LE AAYGA 
        temp -> next = head ;//B KO A PR POINT KRA RHE 

        return temp ;//AB JO STARTING NODE HOGA VOH B YAANI TEMP HOGA 
    }
};
