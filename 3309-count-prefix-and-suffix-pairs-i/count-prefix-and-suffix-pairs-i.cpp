class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                res += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return res;
    }
    bool isPrefixAndSuffix(string s1, string s2) {
        int sz2 = s2.size(), sz1 = s1.size();
        if(sz1 > sz2) return 0;
        return (s2.substr(0, sz1) == s1 && s2.substr(sz2-sz1, sz1) == s1);
    }
};