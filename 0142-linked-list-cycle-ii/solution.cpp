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
    ListNode *detectCycle(ListNode *head) {
       
       if(head == NULL || head -> next == NULL){
            return NULL ;
       }

       ListNode* slow = head ;
       ListNode* fast = head-> next  ;

        //loop mai mai cycle bhi check kr rha hu and yeh bhi check kr rha hu ki agr cycle nhi hai slow == fast hua toh loop break and cycle mil gyi 
       while(slow != fast && fast -> next != NULL && fast -> next -> next != NULL ){
        slow = slow -> next ;
        fast = fast -> next -> next ;
       }
    //    if(fast -> next == NULL || fast -> next -> next == NULL){//iska mtlb cycle nhi hai toh null return krenge 
    //     return NULL ;
    //    }

       //hum cycle nhi hai uske liye yeh bhi likh skte hai ki slow == fast nhi hai tb bhi loop break hua yaani fast yaa fast ka next null hua hoga yaani cycle hai 
        if(slow != fast){
            return NULL ;
        }
       slow = head ;
       //humne slow ko vapis head pr kr diya and ab slow and fast ko ek ek krke aage bda rhe hai jha yeh mile vhi node starting node tha cycle ka 
       while(slow != fast && fast -> next != slow){//yeh  fast -> next != slow yeh condition jb lgegi agr 2 node hi hai and unme cycle hai 
        slow = slow -> next ;
        fast = fast -> next ;
       }

       return slow ;
       
      
    }
};
