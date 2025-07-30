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

    vector<int> ans ;
    ListNode* temp = head ;

    while(temp!=NULL){
        ans.push_back(temp -> val);
        temp = temp -> next ;
    }
    int k = ans.size() - n ;
    ans.erase(ans.begin()+k) ;

    ListNode* first = new ListNode(ans[0]);
    ListNode* curr = first ;
    for(int i=1 ;i<ans.size();i++){
        ListNode* temp = new ListNode(ans[i]);
        curr -> next = temp ;
        curr = temp ;
    }

    return first ;


    }
};
