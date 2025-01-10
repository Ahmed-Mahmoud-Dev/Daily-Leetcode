class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();

        vector<int> freq1(26, 0), freq2(26, 0), tmpFreq(26, 0);
        for(int i=0; i<m; i++) {
            for(char ch: words2[i]) {
                tmpFreq[ch-'a']++;
            }

            for(int j=0; j<26; j++) {
                freq2[j] = max(freq2[j], tmpFreq[j]);
                
                tmpFreq[j] = 0;
            }
        }

        vector<string> res;
        for(int i=0; i<n; i++) {
            for(char ch: words1[i]) {
                freq1[ch-'a']++;
            }

            bool isUniversal = true;
            for(int j=0; j<26; j++) {
                if(freq1[j] < freq2[j]) isUniversal = false;

                // resetting freq2
                freq1[j] = 0;
            }

            if(isUniversal) res.push_back(words1[i]);
        }

        return res;
    }
};