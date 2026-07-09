class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<int> col(n);
        for (int i = 0; i < n; i++) {
            col[i] = i;
        }

        do {
            if (isValid(col)) {
                ans.push_back(buildBoard(col));
            }
        } while (next_permutation(col.begin(), col.end()));

        return ans;
    }

private:
    bool isValid(vector<int>& col) {
        int n = col.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) == abs(col[i] - col[j])) {
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> buildBoard(vector<int>& col) {
        int n = col.size();
        vector<string> board(n, string(n, '.'));

        for (int row = 0; row < n; row++) {
            board[row][col[row]] = 'Q';
        }

        return board;
    }
};