class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0, n = s1.size(), m = s2.size();
        int num1 = 0, num2 = 0;
        while(i < n || j < m) {
            while(i < n && s1[i] != '.') {
                num1 = num1*10 + (s1[i] - '0');
                i++;
            }
            while(j < m && s2[j] != '.') {
                num2 = num2*10 + (s2[j] - '0');
                j++;
            }
            // cout<<num1<<" "<<num2<<" ";
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
            num1 = 0, num2 = 0; 
            i++; j++; // for '.'
        }
        return 0;
    }
};