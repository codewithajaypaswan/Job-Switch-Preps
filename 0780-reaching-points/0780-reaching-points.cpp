class Solution {
public:
    bool solve(int sx, int sy, int tx, int ty) {
        if(sx == tx && sy == ty) return true;
        if(sx > tx || sy > ty) return false;
        if(tx > ty) return solve(sx, sy, tx - ty, ty);
        if(ty > tx) return solve(sx, sy, tx, ty - tx);
        return false;
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // if(sx > sy) swap(sx, sy);
        // return solve(sx, sy, tx, ty);
        while(tx > sx && ty > sy) {
            if(tx > ty) tx %= ty;
            else ty %= tx;
        }
        if(sx == tx && ty >= sy) {
            return (ty - sy)%sx == 0;
        }
        if(sy == ty && tx >= sx) {
            return (tx - sx)%sy == 0;
        }
        return false;
    }
};