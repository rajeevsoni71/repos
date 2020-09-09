#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int cap) {
        this->cp = cap;
        this->head = NULL;
        this->tail = NULL;
    }
    virtual void set(int key, int val) override {
        if (cp <= 0)
            return;
        Node* New_node;
        if (mp.empty()) {
            New_node = new Node(key,val);
            head = tail = New_node;
            mp.emplace(key,New_node);
            return;
        } else {
            //find key in map means it will be part of link list also bcoz map key and linklist key are same.
            std::map<int, Node*>::iterator it = mp.find(key);
            //cout << (it->first) << ":" << (it->second)->key << "," << (it->second)->value;
            //find value in key in map
            //if key ispresent then update thevalue
            if (it != mp.end()) {
                //now update the value
                it->second->value = val;
                // check the place where the key is found
                // 1. it is head, then return without moving the pointer to the key.
                // 2. ,it is tail, then reset the tail to its previous key.
                // 3. or it is in middle, then reset the current-next-prev to current-prev
                if (head == it->second)
                    return;
                if (tail == it->second)
                    tail = tail->prev;
                else
                    it->second->next->prev = it->second->prev;
                //Now reset the head
                //it doesnot matter where we find the key in tail or middle
                //only matter is that curent pointer will reset to head.
                it->second->prev = NULL;
                it->second->next = head;
                head->prev = it->second;
                head = it->second;
            }
            else {// no key present in map
                New_node = new Node(head->prev, head, key, val);
                head->prev = New_node;
                head = New_node;
                mp.emplace(key, New_node);
                // if map size increased then delete the node
                // tail.
                if (mp.size() > cp) {
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next;
                    tail->next = NULL;
                }
            }
        }
    }
    virtual int get(int key) override {
        auto it = mp.find(key);
        if (it != mp.end()) {
            return (it->second)->value;
        } else {
            return -1;
        }
    } //get function
    virtual ~LRUCache() {}
};

int main() {
    int n, capacity, i;
    cout << "Enter the capacity of Cache:";
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        cout << "select command set/get:";
        string command;
        cin >> command;
        if (command == "get") {
            cout << "Enter key to get value:";
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            cout << "Enter key and value:";
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
