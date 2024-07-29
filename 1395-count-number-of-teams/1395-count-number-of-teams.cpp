class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        for(int i=0; i<rating.size(); i++) {
            int less_left = 0, greater_right = 0;
            int greater_left = 0, less_right = 0;
            for(int j=i-1; j>=0; j--) {
                if(rating[i] > rating[j]) 
                    greater_left++;
                else
                    less_left++;
            }
            for(int j=i+1; j<rating.size(); j++) {
                if(rating[i] > rating[j])
                    greater_right++;
                else 
                    less_right++;
            }
            cnt += less_left * greater_right + greater_left*less_right;
        }
        return cnt;
    }
};