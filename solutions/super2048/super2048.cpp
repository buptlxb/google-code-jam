#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<vector<int> > Board;
Board next(Board &board, string dir) {
    int n = board.size();
    if (dir == "right") {
        for (int i = 0; i < n; ++i) {
            int k = n-1;
            for (int j = n-1; j >= 0; --j) {
                if (board[i][j] == 0)
                    continue;
                int m;
                for (m = j - 1; m >= 0; --m)
                    if (board[i][m])
                        break;
                if (m >= 0 && board[i][m] == board[i][j]) {
                    board[i][k--] = 2 * board[i][j];
                    j = m;
                } else if (m >= 0) {
                    board[i][k--] = board[i][j];
                    j = m+1;
                } else {
                    board[i][k--] = board[i][j];
                    break;
                }
            }
            while (k >= 0) {
                board[i][k--] = 0;
            }
        }
    } else if (dir == "up") {
        for (int i = 0; i < n; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                if (board[j][i] == 0)
                    continue;
                int m;
                for (m = j + 1; m < n; ++m)
                    if (board[m][i])
                        break;
                if (m < n && board[m][i] == board[j][i]) {
                    board[k++][i] = 2 * board[j][i];
                    j = m;
                } else if (m < n) {
                    board[k++][i] = board[j][i];
                    j = m-1;
                } else {
                    board[k++][i] = board[j][i];
                    break;
                }
            }
            while (k < n) {
                board[k++][i] = 0;
            }
        }
    } else if (dir == "left") {
        for (int i = 0; i < n; ++i) {
            int k = 0;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0)
                    continue;
                int m;
                for (m = j + 1; m < n; ++m)
                    if (board[i][m])
                        break;
                if (m < n && board[i][m] == board[i][j]) {
                    board[i][k++] = 2 * board[i][j];
                    j = m;
                } else if (m < n) {
                    board[i][k++] = board[i][j];
                    j = m-1;
                } else {
                    board[i][k++] = board[i][j];
                    break;
                }
            }
            while (k < n) {
                board[i][k++] = 0;
            }
        }
    } else if (dir == "down") {
        for (int i = 0; i < n; ++i) {
            int k = n-1;
            for (int j = n-1; j >= 0; --j) {
                if (board[j][i] == 0)
                    continue;
                int m;
                for (m = j - 1; m >= 0; --m)
                    if (board[m][i])
                        break;
                if (m >= 0 && board[m][i] == board[j][i]) {
                    board[k--][i] = 2 * board[j][i];
                    j = m;
                } else if (m >= 0) {
                    board[k--][i] = board[j][i];
                    j = m+1;
                } else {
                    board[k--][i] = board[j][i];
                    break;
                }
            }
            while (k >= 0) {
                board[k--][i] = 0;
            }
        }
    } else
        cerr << "error!" << endl;
    return board;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int n;
        string dir;
        cin >> n >> dir;
        Board board(n, vector<int>(n, 0));
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cin >> board[j][k];
        Board ret = next(board, dir);
        cout << "Case #" << i << ": " << endl;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << ret[j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
