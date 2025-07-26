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
    bool hasCycle(ListNode *head) {
       /*
       method 1
       map<ListNode* , bool> visited ;
       ListNode*temp = head ;

       while(temp!=NULL){
        if(visited[temp]==true){
            return true ;
        }
        visited[temp] = true ;
        temp = temp -> next ;
       } 

       return false ;
       */

       //method 2 

       ListNode* slow = head ;
       ListNode* fast = head ;

       while(fast!=NULL && fast -> next !=NULL){
         fast = fast -> next -> next ;
         slow = slow -> next ;

         if(slow == fast ){
            return true ;
         }

       }
       return false ;
    }
};
