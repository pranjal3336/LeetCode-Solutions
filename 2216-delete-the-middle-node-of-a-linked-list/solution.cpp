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
        // vector<int> ans ;
        // if(head -> next == NULL){
        //     return NULL ;
        // }

        // ListNode* temp = head ;
        // while(temp!=NULL){
        //     ans.push_back(temp -> val);
        //     temp = temp -> next ;
        // }

        // int n = ans.size();
        // int s=0;
        // int e = n-1 ;
        // int index = -1 ;

        // int mid = (s+e)/2 ;

        // if(n%2!=0){
        //     index = mid ;
        //     ans.erase(ans.begin() + index );
        // }
        // else{
        //     index = mid + 1;
        //     ans.erase(ans.begin() + index );

        // }

        // ListNode* first = new ListNode(ans[0]);
        // ListNode* curr = first ;
        // for(int i=1;i< ans.size();i++){
        //     ListNode* temp = new ListNode(ans[i]) ;
        //     curr -> next = temp ;
        //     curr = temp ;
        // }

        // return first ;

        //hum direct bhi kr skte hai bina array ka use kiye slow and fast pointer ka use krke jisse 
        //jab fast pointer last yaa null ko point krega jab slow pointer exactly mid mai hoga and ek prev pointer lenge jo just slow se peeche hoga and voh direct slow ka next yaani aage wale se connect ho jayga

        if(head == NULL || head->next == NULL){
            return NULL ;
        }

        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prev = NULL ;

        while(fast != NULL && fast->next!=NULL){
            prev = slow ;
            slow = slow->next ;//isko 1 step 
            fast = fast->next->next ;//fast ko 2 step bda rhe hai 
        }

        //jab loop khtm yaani slow mid pahuch gya and fast end mai yaa toh bahr ho gya 

        prev->next = slow->next ;
        //ab slow bhi next element ko point kr rha tha usse hta denge NULL ko point krakr delete kr denge memory se 
        slow->next = NULL ;

        delete slow ;

        return head ;

    }
};
