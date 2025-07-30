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


public:
    ListNode* oddEvenList(ListNode* head) {
    if(head == NULL){
        return head ;
    } 

    vector<int> ans ;
    ListNode* temp = head ;

    while(temp!=NULL){
        ans.push_back(temp -> val);
        temp = temp -> next ;
    }
    vector<int> odd ;
    vector<int> even ;

    for(int i=0;i<ans.size();i++){
        if(i%2==0){
            even.push_back(ans[i]);
        }
        else{
             odd.push_back(ans[i]);
        }
    }

    ListNode* first = new ListNode(even[0]);
    ListNode* curr = first ;
    for(int i=1 ;i<even.size();i++){
        ListNode* temp = new ListNode(even[i]);
        curr -> next = temp ;
        curr = temp ;
    }

    for(int i=0 ;i<odd.size();i++){
        ListNode* temp = new ListNode(odd[i]);
        curr -> next = temp ;
        curr = temp ;
    }

    return first ;
    

    
    

    }
    
};
