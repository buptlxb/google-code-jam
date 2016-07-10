#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

#define R 50
#define C 50

int board[R][C];
int rain[R][C];
bool visit[R][C];
int r, c;
int hight;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx == r || ny == c)
            continue;
        if (rain[x][y] < rain[nx][ny] && rain[nx][ny] != board[nx][ny]) {
            rain[nx][ny] = max(rain[x][y], board[nx][ny]);
            dfs(nx, ny);
        }
    }
}

int solve()
{
    int ret = 0;
    for (int x = 1; x < r-1; ++x) {
        for (int y = 1; y < c-1; ++y) {
            rain[x][y] = hight;
        }
    }
    /*
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            cout << rain[x][y] << " ";
        }
        cout << endl;
    }
    */
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            if (visit[x][y])
                continue;
            dfs(x, y);
        }
    }
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            //cout << rain[x][y] << " ";
            ret += rain[x][y] - board[x][y];
        }
        //cout << endl;
    }
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        memset(visit, false, sizeof(visit));
        cin >> r >> c;
        hight = 0;
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                cin >> board[x][y];
                rain[x][y] = board[x][y];
                hight = max(hight, board[x][y]);
            }
        }
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    cout << flush;
    return 0;
}
