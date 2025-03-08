/*
Clone linked list with next and random pointer

Given a linked list of size n where each node has two links: 
next pointer pointing to the next node and random pointer to any random node in the list. 
The task is to create a clone of this linked list.
*/

/*
[Naive Approach - 1] Using Hashing - O(2n) Time and O(2n) Space
The idea is to create a new node corresponding to each node in the original linked list 
and store the new nodes in a hash table. Now, again traverse the original linked list and update the next 
and random pointers of new nodes corresponding to every original node.
*/

class Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp =new Node(d);
        if(tail == NULL){
            tail = temp;
            head= temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = tail ->next;
        }
        
    }
    
    
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        unordered_map<Node*, Node*>oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode!=NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode -> next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode!=NULL){
            cloneNode -> arb = oldToNew[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }

};


/*

[Expected Approach] By Inserting Nodes In-place - O(3n) Time and O(1) Space
The idea is to create duplicate of a node and instead of storing in a separate hash table, 
we can insert it in between the original node and the next node. 
Now, we will have new nodes at alternate positions.

Now for a node X its duplicate will be X->next and the random pointer of the duplicate 
should point to X->random->next (as that is the duplicate of X->random). 
So, iterate over the entire linked list to update the random pointer of all the cloned nodes
 and then iterate again to separate the original linked list and the cloned linked list.
 */



/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
    private:
      void insertAtTail(Node* &head, Node* &tail, int d){
          Node* newNode = new Node(d);
          
          if(head==NULL){
              head = newNode;
              tail = newNode;
              return;
          }else{
              tail->next = newNode;
              tail = newNode;
          }
      }
    public:
      Node *cloneLinkedList(Node *head) {
          
          Node* cloneHead=NULL;
          Node* cloneTail = NULL;
          
          Node* temp = head;
          
          while(temp!=NULL){
              insertAtTail(cloneHead, cloneTail, temp->data);
              temp=temp->next;
          }
          
          Node* originalNode = head;
          Node* cloneNode = cloneHead;
          
          while(originalNode!=NULL && cloneNode != NULL){
              Node* next = originalNode->next;
              originalNode->next = cloneNode;
              originalNode = next;
              
              next = cloneNode->next;
              cloneNode->next = originalNode;
              cloneNode = next;
          }
          
          temp = head;
          
          while(temp!=NULL){
              if(temp->next != NULL){
                  temp->next->random = temp->random ? temp->random->next : temp->random;
              }
              temp = temp->next->next;
          }
          
          originalNode=head;
          cloneNode=cloneHead;
          
          while(originalNode!=NULL && cloneNode != NULL){
              originalNode->next = cloneNode->next;
              originalNode = originalNode->next;
              
              if(originalNode != NULL)
                  cloneNode->next = originalNode->next;
              cloneNode = cloneNode->next;
          }
          
          return cloneHead;
      
      }
  };

// Time Complexity: O(3n) = O(n)
// Space Complexity: O(1)