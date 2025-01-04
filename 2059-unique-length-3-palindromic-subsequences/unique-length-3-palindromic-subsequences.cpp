class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int freq[26][n+1];
        vector<pair<int, int>> charPosition(26, {-1, -1});
        memset(freq, 0, sizeof(freq));

        for(int i=0; i<n; i++) {
            if(charPosition[s[i]-'a'].first == -1) charPosition[s[i]-'a'].first = i;
            else charPosition[s[i]-'a'].second = i;
        }

        for(int i=0; i<26; i++) {
            for(int j=0; j<n; j++) {
                freq[i][j+1] = freq[i][j] + (s[j] == char(i+'a'));
            }
        }

        int l, r, res=0;
        for(int i=0; i<26; i++) {
            if(charPosition[i].second == -1) continue;

            l = charPosition[i].first, r = charPosition[i].second;
            for(int j=0; j<26; j++) {
                if(i == j && freq[j][r+1] - freq[j][l] == 2) continue;
                res += (freq[j][r+1] - freq[j][l] > 0);
            }
            cout << char(i + 'a') << ' ' << res << endl;
        }
        return res;
    }
};