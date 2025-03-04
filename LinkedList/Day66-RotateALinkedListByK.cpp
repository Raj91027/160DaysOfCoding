
/*
Rotate a Linked List

Given a singly linked list and an integer k, the task is to rotate the linked list to the left by k places.

Examples:

Input: linked list = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40

[Naive Approach] Shifting head node to the end k times - O(n * k) Time and O(1) Space
To rotate a linked list to the left k places, we can repeatedly move the head node to the end of the linked list k times.
*/

// C++ program to rotate a linked list by
// changing moving first node to end k times

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to rotate the linked list
// left by k nodes
Node *rotate(Node *head, int k) {
    if (k == 0 || head == nullptr)
        return head;

    // Rotate the list by k nodes
    for (int i = 0; i < k; ++i) {
        Node *curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        
        // Move the first node to the last
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = nullptr;
    }
    return head;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {

    // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
  
    head = rotate(head, 6);
    printList(head);

    return 0;
}


/*
The time complexity of the rotate() function is O(n * k) where n is the number of nodes in the linked list and k is the number of rotations to be performed. 
The space complexity is O(1) as we are not using any extra space.  
*/            

// [Optimized Approach] Using Efficient Approach - O(n) Time and O(1) Space 
// The idea is to find the length of the linked list and then find the kth node from the end of the linked list. 
//Then, we can make the kth node as the new head of the linked list and the k-1th node as the new tail of the linked list.


class Solution {
    public:
      Node* rotate(Node* head, int k) {
          
          if(head == NULL)
              return head;
              
          int count=0;
          
          Node* temp = head;
          while(temp!=NULL){
              temp = temp->next;
              count++;
          }
          k %=count;
          if(k==0 || k==count)
              return head;
              
          temp = head;
          while(k > 1){
              temp = temp->next;
              k--;
          }
          
          Node* headToRev = temp->next;
          
          temp->next = NULL;
          
          Node* curr = headToRev;
          while(curr->next != NULL){
              curr = curr -> next;
          
          }
          
          curr -> next = head;
          
          head = headToRev;
          return head;
      }
  };