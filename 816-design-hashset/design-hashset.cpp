class MyHashSet {
public:
    
    // Maximum key = 10^6
    // Direct Address Table Approach
    // Time Complexity:
    // add()      -> O(1)
    // remove()   -> O(1)
    // contains() -> O(1)
    
    vector<bool> hash;
    
    MyHashSet() {
        // size = 10^6 + 1 because keys can be from 0 to 10^6
        hash.resize(1000001, false);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */