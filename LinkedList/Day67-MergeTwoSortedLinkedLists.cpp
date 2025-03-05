/*
Merge two sorted linked lists

Given two sorted linked lists consisting of n and m nodes respectively. 
The task is to merge both of the lists and return the head of the merged list.
// the merging process

*/



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

Node *merge(Node *head1, Node *head2) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    // Iterate through both linked lists
    while (head1 != nullptr && head2 != nullptr) {
      
        // Add the smaller node to the merged list
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // If any list is left, append it to
    // the merged list
    if (head1 != nullptr) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    // Return the merged list starting
    // from the next of dummy node
    return dummy->next;
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
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);

    // Create another hard-coded linked list:
    // 15 -> 25 -> 35 -> 45
    Node *head2 = new Node(15);
    head2->next = new Node(25);
    head2->next->next = new Node(35);
    head2->next->next->next = new Node(45);

    Node *head = merge(head1, head2);
    printList(head);

    return 0;
}


// Time Complexity: O(n + m)
// Space Complexity: O(1)

// The time complexity of the merge() function is O(n + m) where n and m are the number of nodes in the two linked lists.
// The space complexity is O(1) as we are not using any extra space.
// The merge() function merges two sorted linked lists in a single sorted linked list.
// The function takes the heads of the two linked lists as input and returns the head of the merged list.
// The function iterates through both linked lists and adds the smaller node to the merged list.
// If any list is left, it appends the remaining nodes to the merged list.
// Finally, it returns the merged list starting from the next of the dummy node.
// The printList() function is used to print the elements of the linked list.
// In the main() function, two hard-coded linked lists are created, and the merge() function is called to merge the two lists.
// The merged list is then printed using the printList() function.
// The output of the program will be:
// 10 15 20 25 30 35 40 45


/*
[Naive Approach] By Using Array - O((n+m)*log(n+m)) Time and O(n+m) Space
The idea is to merge two sorted linked lists into one sorted linked list. 
First, the elements from both linked lists are extracted and stored in an array. 
This allows easy sorting of the values. After sorting, a new linked list is 
created by sequentially inserting the sorted elements from the array. 
Finally, the merged sorted linked list is returned.
*/

// C++ program to merge two sorted linked lists
// using array
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node *sortedMerge(Node *head1, Node *head2) {
    vector<int> arr;

    // Pushing the values of the first linked list
    while (head1 != nullptr) {
        arr.push_back(head1->data);
        head1 = head1->next;
    }

    // Pushing the values of the second linked list
    while (head2 != nullptr) {
        arr.push_back(head2->data);
        head2 = head2->next;
    }

    // Sorting the vector
    sort(arr.begin(), arr.end());

    // Creating a new list with sorted values
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    for (int i = 0; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return dummy->next;
}

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    // Merging the two sorted linked lists
    Node *res = sortedMerge(head1, head2);

    printList(res);

    return 0;
}


// Time Complexity: O((n + m) * log(n + m))
// Space Complexity: O(n + m)

/*

[Better Approach] Using Recursive Merge - O(n+m) Time and O(n+m) Space
The idea is to merge two sorted linked lists using recursion. 
The base cases handle the scenarios where one of the lists is empty, 
in which case the other list is returned directly. 
In the recursive step, the function compares the data of the current 
nodes of both lists and attaches the smaller node to the merged list. 
The function then recursively merges the remaining part of the list. 
This process continues until both lists are fully merged. 
This approach eliminates the need for extra space and efficiently merges the lists.
*/

// C++ program to merge two sorted linked
// lists recursively
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists recursively
Node* sortedMerge(Node* head1, Node* head2) {

    // Base cases
    if (head1 == nullptr) 
        return head2;
    if (head2 == nullptr) 
        return head1;

    // Recursive merging based on smaller value
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    } else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

// Function to print the linked list
void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // First linked list: 5 -> 10 -> 15
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);
    printList(res);

    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

// The time complexity of the sortedMerge() function is O(n + m) where n and m are the number of nodes in the two linked lists.
// The space complexity is also O(n + m) due to the recursive calls and stack space used.
// The sortedMerge() function merges two sorted linked lists recursively.
// The base cases handle the scenarios where one of the lists is empty, in which case the other list is returned directly.
// In the recursive step, the function compares the data of the current nodes of both lists and attaches the smaller node to the merged list.
// The function then recursively merges the remaining part of the list.
// This process continues until both lists are fully merged.
// The printList() function is used to print the elements of the linked list.
// In the main() function, two hard-coded linked lists are created, and the sortedMerge() function is called to merge the two lists.
// The merged list is then printed using the printList() function.
// The output of the program will be:
// 2 3 5 10 15 20
