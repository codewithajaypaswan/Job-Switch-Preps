class TreeAncestor {
public:
    vector<vector<int>>parent;
    TreeAncestor(int n, vector<int>& p) {
        parent.resize(20, vector<int>(n, -1));
        
        for(int i=0; i<p.size(); i++) 
            parent[0][i] = p[i];
        for(int i=1; i<20; i++) {
            for(int node=0; node<p.size(); node++) {
                int nodep = parent[i-1][node];
                if(nodep != -1) parent[i][node] = parent[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<20; i++) {
            if(k & (1<<i)) {
                node = parent[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
9 = 2^3 + 2^0
10 = 2^3 + 2^1
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */