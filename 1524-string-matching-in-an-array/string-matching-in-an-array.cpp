class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        for(int i=0; i<n; i++) {
            bool isSubstring = 0;
            for(int j=0; j<n; j++) {
                if(j == i) continue;
                if(words[i].size() <= words[j].size() && words[j].find(words[i]) < words[j].size()) isSubstring = 1;

            }
            if(isSubstring) res.push_back(words[i]);
        }

        return res;
    }
};