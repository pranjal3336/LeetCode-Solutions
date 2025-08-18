/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
  
  void inserAttail(Node* &head , Node* &tail , int data){
      Node* newNode = new Node(data);
      if(head == NULL){
          head = newNode ;
          tail = newNode ;
          return ;
      }
      else{
          tail -> next = newNode ;
          tail = newNode ;
      }
  }
public:
    Node* copyRandomList(Node* head) {
      //method 1 yeh isme time complexity O(n) hai and space bhi O(n) h kyonki map extra memory leta h
        
        //step 1 -> create a clone list 
        
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL ;
        
        Node* temp = head ;
        
        while(temp!=NULL){
            inserAttail(cloneHead , cloneTail , temp -> val) ;
            temp = temp -> next ;
        }
        
        //step 2 -> create a map 
        
        unordered_map<Node* , Node*> mapping ;
        
        Node* originalNode = head ;
        Node* cloneNode = cloneHead ;
        while(originalNode!=NULL){
            mapping[originalNode] = cloneNode ;
            originalNode = originalNode -> next ;
            cloneNode = cloneNode -> next ;
        }
        
        //set up head 
        
        originalNode = head ;
        cloneNode = cloneHead ;
        
        //step 3 -> ab random pointers ko map krana h
        
        while(originalNode!=NULL){
            
            cloneNode -> random = mapping[originalNode -> random];
        
            originalNode = originalNode -> next ;
            cloneNode = cloneNode -> next ; 
        }
        
        
        
        return cloneHead ;
         
    }
};
