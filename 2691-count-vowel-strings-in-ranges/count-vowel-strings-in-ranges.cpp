class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();

        vector<int> freq(n+1);
        for(int i=0; i<n; i++) {
            freq[i+1] = freq[i] + (isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]));
        }

        vector<int> res;
        for(int i=0; i<m; i++) {
            cout << freq[queries[i][1] + 1] - freq[queries[i][0]];
            res.push_back(freq[queries[i][1] + 1] - freq[queries[i][0]]);
        }

        return res;
    }

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};