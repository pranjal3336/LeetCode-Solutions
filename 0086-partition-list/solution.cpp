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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1) ;
        ListNode* smallptr = small ;

        ListNode* large = new ListNode(-1) ;
        ListNode* largeptr = large ;

        while(head != NULL){
            if(head -> val < x){//ek trh se small elements ki list bn rhi hai 
                // ListNode* temp = new ListNode(head -> val) ; //ab maine bina new node ke original link ko hi change kreke partition kr diya 
                smallptr -> next = head ;
                smallptr = head  ;
            }
            else{//greater or equal to x ki list bn rhui hai 
                // ListNode* temp = new ListNode(head -> val) ;
                largeptr -> next = head ;
                largeptr = head  ;
            }

            head = head -> next ;
        }

        smallptr -> next = large -> next ;//end mai smallptr ko large ke next yaani greater or jo right part hai uske first element se link kr rhe hai 
        largeptr -> next = NULL ;//end mai largeptr ko null pr point kra denge kyonki yeh last element hai and yeh kisi se link nhi hona chahiye 
        return small -> next ; //small ka next yaani small toh dummy node hai uska next yaani first element hai vhi return hoga 


    }
};
