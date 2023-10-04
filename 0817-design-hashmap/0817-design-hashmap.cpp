class MyHashMap {
private:
    map<int,int> mp;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            mp.erase(key);
        mp.insert({key,value});
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
            return mp[key];
        return -1;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */