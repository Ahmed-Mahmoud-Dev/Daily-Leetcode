class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), freq[26] = {0};

        for(int i=0; i<n; i++) {
            freq[s[i]-'a']++;
        }
        
        int res = 0;
        for(auto curFreq: freq) {
            if(curFreq) {
                if(curFreq&1) res++;
                else res+=2;
            }
        }
        return res;
    }
};