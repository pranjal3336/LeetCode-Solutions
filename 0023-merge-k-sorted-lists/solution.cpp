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
    ListNode* mergeTwoList(ListNode* list1 , ListNode* list2){
        if(list1 == NULL){
            return list2 ;
        }
        if(list2 == NULL){
            return list1 ;
        }


        if(list1->val <= list2->val){
            list1->next = mergeTwoList(list1->next , list2) ;
            return list1 ;
        }
        else{
            list2->next = mergeTwoList(list2->next , list1) ;
            return list2 ;
        }
    }

    ListNode* partitionAndMerge(vector<ListNode*>& lists , int s , int e){
        if(s==e){
            return lists[s] ;
        }

        int mid = s +(e-s)/2 ;

        ListNode* L1 = partitionAndMerge(lists , s , mid) ;
        ListNode* L2 = partitionAndMerge(lists , mid+1 , e) ;

        return mergeTwoList(L1 , L2) ;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() ==0){
            return NULL ;
        }
        return partitionAndMerge(lists , 0 , lists.size()-1) ;
    }
};
