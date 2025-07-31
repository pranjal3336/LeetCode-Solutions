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
    ListNode* deleteMiddle(ListNode* head) {
        vector<int> ans ;
        if(head -> next == NULL){
            return NULL ;
        }

        ListNode* temp = head ;
        while(temp!=NULL){
            ans.push_back(temp -> val);
            temp = temp -> next ;
        }

        int n = ans.size();
        int s=0;
        int e = n-1 ;
        int index = -1 ;

        int mid = (s+e)/2 ;

        if(n%2!=0){
            index = mid ;
            ans.erase(ans.begin() + index );
        }
        else{
            index = mid + 1;
            ans.erase(ans.begin() + index );

        }

        ListNode* first = new ListNode(ans[0]);
        ListNode* curr = first ;
        for(int i=1;i< ans.size();i++){
            ListNode* temp = new ListNode(ans[i]) ;
            curr -> next = temp ;
            curr = temp ;
        }

        return first ;

    }
};
