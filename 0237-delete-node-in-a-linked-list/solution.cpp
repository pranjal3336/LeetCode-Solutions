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
    void deleteNode(ListNode* node) {
        
        if(node == NULL ||node -> next == NULL ){//yaani jb node hai hi nhi yaa phir ek 1 node hai toh return 
            return ;
        }
       node ->val = node ->next -> val ;
       ListNode* temp = node ->next  ;
       node -> next = temp -> next ;
       delete temp ;

    }
};
