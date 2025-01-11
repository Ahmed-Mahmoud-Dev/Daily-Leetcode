class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26);
        int pairs = 0;
        for(auto ch: s) {
            if(freq[ch-'a']) freq[ch-'a'] = 0, pairs++;
            else freq[ch-'a'] = 1;
        }
        int singles = s.size() - (2*pairs);
        
        if(k > s.size()) return false;
        return (k >= singles);
    }
};