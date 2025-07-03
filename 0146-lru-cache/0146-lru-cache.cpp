class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key1,int value1) {
            key = key1;
            value=value1;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(Node* node) {
        Node* currAfterHead = head->next;
        node->next = currAfterHead;
        node->prev = head;
        head->next=node;
        currAfterHead->prev=node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    int get(int key1) {
        if (mp.find(key1) == mp.end()) {
            return -1;
        }
        Node* node = mp[key1];
        int res=node->value;
        mp.erase(key1);
        deleteNode(node);
        insertAtHead(node);
        mp[key1]=head->next;
        return res;
    }

    void put(int key1, int value1) {
        if (mp.find(key1) != mp.end()) {
            Node* node = mp[key1];
            mp.erase(key1);
            deleteNode(node);
        } 
      
        if (mp.size() == cap) {
            Node* node = tail->prev;
            mp.erase(node->key);
            deleteNode(node);
        }
        Node* node = new Node(key1, value1);
        insertAtHead(node);
        mp[key1]=node;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */