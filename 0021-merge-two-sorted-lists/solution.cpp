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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Agar list1 khatam ho jaye, toh list2 return kar do
        if(list1 == NULL){
            return list2 ;
        }
        // Agar list2 khatam ho jaye, toh list1 return kar do
        if(list2 == NULL){
            return list1 ;
        }
        // Agar list1 ka value chhota ya barabar hai toh yhi phle aayga and iske next mai iske aage ka part and list2 bhenge 
        if(list1->val <= list2->val){
            list1-> next = mergeTwoLists(list1->next , list2) ;
            return list1 ;
        }
        // Agar list2 ka value chhota hai
        else{
            list2-> next = mergeTwoLists(list2->next , list1) ;
            return list2 ;
        }
        //yha tk code aaayga hi nhi upr se hi return ho jayga answer 
        return NULL ;
    }
};
