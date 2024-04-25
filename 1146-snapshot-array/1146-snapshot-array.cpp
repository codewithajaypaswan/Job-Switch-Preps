class SnapshotArray {
public:
    unordered_map<int, map<int, int>>mp;
    int curSnap;
    SnapshotArray(int length) {
        map<int, int>cur;
        cur[0] = 0;
        curSnap = 0;
        for(int i=0; i<length; i++) {
            mp[i] = cur;
        }
    }
    
    void set(int index, int val) {
        mp[index][curSnap] = val;
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */