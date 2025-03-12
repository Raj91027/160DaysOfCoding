/*
LRU Cache Implementation using Doubly Linked List

Design a data structure that works like a LRU(Least Recently Used) Cache. 
The LRUCache class has two methods get() and put() which are defined as follows.

LRUCache (Capacity c): Initialize LRU cache with positive size capacity c.
get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. 
If not present, add the key-value pair to the cache. If the cache reaches its capacity it 
should remove the key-value pair with the lowest priority.
Example:

Input: [LRUCache cache = new LRUCache(2) , put(1 ,1) , put(2 ,2) , get(1) , put(3 ,3) , get(2) , put(4 ,4) , get(1) , get(3) , get(4)]
Output: [1 ,-1, -1, 3, 4]
Explanation: The values mentioned in the output are the values returned by get operations.
*/

/*
Thoughts about Implementation Using Arrays, Hashing and/or Heap
We use an array of triplets, where the items are key, value and priority

get(key) : We linearly search the key. If we find the item, we change priorities of all impacted and make the new item as the highest priority.
put(key): If there is space available, we insert at the end. If not, we linearly search items of the lowest priority and replace that item with the new one. 
We change priorities of all and make the new item as the highest priority.

Time Complexities of both the operations is O(n)

Can we make both operations in O(1) time? we can think of hashing. With hashing, we can insert, get and delete in O(1) time, 
but changing priorities would take linear time. We can think of using heap along with hashing for priorities. We can find and remove the least recently used (lowest priority) in O(Log n) time which is more than O(1) and changing priority in the heap would also be required.

Using Doubly Linked List and Hashing
The idea is to keep inserting the key-value pair at the head of the doubly linked list. 
When a node is accessed or added, it is moved to the head of the list (right after the dummy head node). 
This marks it as the most recently used. When the cache exceeds its capacity, the node at the tail (right before the dummy tail node) is removed as it represents the least recently used item.

Doubly-Linked-List-Representation-Of-LRU-Cache-2.webpDoubly-Linked-List-Representation-Of-LRU-Cache-2.webp


Below is the implementation of the above approach: 
*/

// C++ program to implement LRU Least Recently Used)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// LRU Cache class
class LRUCache
{
  public:
  
    // Constructor to initialize the cache with a given capacity
    int capacity;
    unordered_map<int, Node *> cacheMap;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to get the value for a given key
    int get(int key) {
      
        if (cacheMap.find(key) == cacheMap.end())
            return -1;
  

        Node *node = cacheMap[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node *oldNode = cacheMap[key];
            remove(oldNode);
              delete oldNode;
          
        }

        Node *node = new Node(key, value);
        cacheMap[key] = node;
        add(node);
       
       
        if (cacheMap.size() > capacity) {
            Node *nodeToDelete = tail->prev;
            remove(nodeToDelete);
            cacheMap.erase(nodeToDelete->key);
              delete nodeToDelete;
        }
    }

    // Add a node right after the head 
      // (most recently used position)
    void add(Node *node) {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    // Remove a node from the list
    void remove(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

int main(){
    LRUCache cache(2);
  
    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}

/*
Output:
1
-1
-1
3
4
*/

/*
Time Complexity: O(1) for both get and put operations.
Space Complexity: O(n) where n is the capacity of the cache.
*/


/*
Using Inbuilt Doubly Linked List
The idea is to use inbuilt doubly linked list, it simplifies the implementation by avoiding the need to manually 
manage a doubly linked list while achieving efficient operations. Example - C++ uses a custom doubly linked list as std::list.

Note: Python's standard library does not include a built-in doubly linked list implementation. 
To handle use cases that typically require a doubly linked list, such as efficiently managing elements at both ends of a sequence, 
Python provides the collections.deque class. While deque stands for double-ended queue, it essentially functions as a doubly linked list with efficient operations on both ends.

Below is the implementation of the above approach: 
*/

// C++ program to implement LRU Least Recently Used) using
//Built-in Doubly linked list
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  public:
    int capacity;
    list<pair<int, int>> List;

    // Map from key to list iterator
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    // Constructor to initialize the 
      //cache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Function to get the value for a given key
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        }

        // Move the accessed node to the 
          //front (most recently used position)
        int value = it->second->second;
        List.erase(it->second);
        List.push_front({key, value});

        // Update the iterator in the map
        cacheMap[key] = List.begin();
        return value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // Remove the old node from the list and map
            List.erase(it->second);
            cacheMap.erase(it);
        }

        // Insert the new node at the front of the list
        List.push_front({key, value});
        cacheMap[key] = List.begin();

        // If the cache size exceeds the capacity,
          //remove the least recently used item
        if (cacheMap.size() > capacity) {
            auto lastNode = List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};

int main() {
  
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}

/*
Output:

1
-1
-1
3
4
*/

/*
Time Complexity: O(1) for both get and put operations.
Space Complexity: O(n) where n is the capacity of the cache.
*/
