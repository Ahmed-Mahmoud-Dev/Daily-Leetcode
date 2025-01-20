class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size(), arrSize = arr.size();

        vector<int> freqOnRows(rows), freqOnCols(cols);
        const int mx = 1e5+1;
        vector<pair<int, int>> row_col(mx, {-1, -1});

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                row_col[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<arrSize; i++) {
            if(row_col[arr[i]].first != -1) {
                pair<int, int> cur = row_col[arr[i]];
                freqOnCols[cur.second]++;
                freqOnRows[cur.first]++;

                if(freqOnRows[cur.first] == cols || freqOnCols[cur.second] == rows) {
                    return i;
                }
            }
        }

        return arrSize-1;
    }
};