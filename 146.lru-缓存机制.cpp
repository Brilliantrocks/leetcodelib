/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include <unordered_map>

struct DLnode{
    DLnode* next;
    DLnode* prev;
    int key,value;
    DLnode(){
        next = nullptr;
        prev = nullptr;
        key = 0;
        value = 0;
    }
    DLnode(int key, int value){
        next = nullptr;
        prev = nullptr;
        this->key = key;
        this->value = value;        
    }
};

class LRUCache {
private:
    std::unordered_map<int,DLnode*> cache;
    DLnode* head;
    DLnode* tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
    head = new DLnode();
    tail = new DLnode();
    size = 0;
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;
        DLnode* temp = cache[key];
        movetohaed(temp);
        return (temp->value);
    }
    
    void put(int key, int value) {
        if (!cache.count(key)){
            DLnode* temp = new DLnode(key,value);
            addtohead(temp);
            cache[key] = temp;
            if (++size > capacity){
                DLnode* gabage = removetail();
                cache.erase(gabage->key);
                delete gabage;
                --size;
            }
        }
        else {
            DLnode* temp = cache[key];
            temp->value = value;
            movetohaed(temp);
        }
        
    }

    void addtohead(DLnode* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removenode(DLnode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLnode* removetail(){
        DLnode* node = tail->prev;
        removenode(node);
        return node;
    }

    void movetohaed(DLnode* node){
        removenode(node);
        addtohead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

