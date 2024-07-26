class TopVotedCandidate {
public:
    unordered_map<int, int>mp;
    vector<int>time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        time = times;
        unordered_map<int, int>count;
        int lead = -1;
        for(int i=0; i<persons.size(); i++) {
            count[persons[i]]++;
            if(count[persons[i]] >= count[lead]) {
                lead = persons[i];
            }
            mp[times[i]] = lead;
        }
    }
    
    int q(int t) {
        auto x = upper_bound(time.begin(), time.end(), t); // nearest time to valid time
        return mp[*(x - 1)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */