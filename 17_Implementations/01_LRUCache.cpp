/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

1) LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
2) int get(int key) Return the value of the key if the key exists, otherwise return -1.
3) void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 
*/

class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    //key, address of node
    unordered_map<int,node*> mp;
    LRUCache(int capacity){
        cap = capacity; 
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node* newNode){
        node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void delNode(node* existingNode){
        node* delPrev = existingNode->prev;
        node* delNext = existingNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            delNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* existingNode = mp[key];
            mp.erase(key);
            delNode(existingNode);
        }
        if(cap == mp.size()){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        node* newNode = new node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

