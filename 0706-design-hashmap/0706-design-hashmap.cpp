class MyHashMap {
public:
    vector<list<pair<int,int>>>vp;
    int size = 0;
    MyHashMap() {
        vp.resize(1000);
        size = 1000;
    }
    
    int getHash(int key) {
        return key%size;
    }
    void put(int key, int value) {
        int ind = getHash(key);
        auto &v = vp[ind];
        for(auto &it:v) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        vp[ind].push_back({key, value});
    }
    
    int get(int key) {
        int ind = getHash(key);
        auto &v = vp[ind];
        for(auto &it:v) {
            if(it.first == key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int ind = getHash(key);
        auto &v = vp[ind];
        for(auto &it:v) {
            if(it.first == key) {
                vp[ind].remove(it);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */