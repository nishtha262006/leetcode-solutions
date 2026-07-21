// LeetCode 146 - LRU Cache

// Difficulty: Medium

// Approach:

// 1. Use a **Hash Map** to store the mapping from keys to nodes.
// 2. Use a **Doubly Linked List** to maintain the order of recently used items.
// 3. Keep the most recently used node at the front and the least recently used node at the back.
// 4. For a `get(key)` operation:

//    * If the key exists, move the corresponding node to the front and return its value.
//    * Otherwise, return `-1`.
// 5. For a `put(key, value)` operation:

//    * If the key already exists, update its value and move it to the front.
//    * Otherwise, insert a new node at the front.
//    * If the cache exceeds its capacity, remove the node at the back and delete its entry from the hash map.
// 6. Return results as required.

// Time Complexity:

// * `get()` → O(1)
// * `put()` → O(1)

// Space Complexity: O(capacity)

// * The hash map and doubly linked list together store at most `capacity` nodes.




class LRUCache {
public:

    class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    unordered_map<int,Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){

            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        Node* node = new Node(key,value);

        mp[key]=node;

        insert(node);

        if(mp.size()>capacity){

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};