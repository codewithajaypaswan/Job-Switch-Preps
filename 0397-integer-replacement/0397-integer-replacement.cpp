class Solution {
public:
    // ex 59 -> 60 -> 30 -> 15 -> 16 -> 8 -> 4 -> 2 -> 1.   59 -> 58 -> 29 -> 28 -> 14 -> 7 -> 6 -> 3 -> 2 -> 1
    int integerReplacement(int n) {
        if(n==INT_MAX) return 32;
        int cnt = 0;
        while(n>1) {
            if(n%2==0) n = n/2;
            else {
                if((n+1)%4==0 && n != 3) n++;
                else n--;
            }
            cnt++;
        }
        return cnt;
    }
};
/*

class Solution {
private:
    unordered_map<int, int> visited;

public:
    int integerReplacement(int n) {        
        if (n == 1) { return 0; }
        if(visited.count(n)) return visited[n];  
        if (n%2 == 1) {
            visited[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        } else {
            visited[n] = 1 + integerReplacement(n / 2);
        }
        return visited[n];
        
    }
};

*/