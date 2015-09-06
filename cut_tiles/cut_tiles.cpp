#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &requires, int &k, int a, int b) {
    if (a < b) {
        dfs(requires, k, b, a);
        return;
    }
    int i = 0;
    while ((1 << i) <= b)
        ++i;
    --i;
    while (i >= 0 && requires[i] == 0)
        --i;
    if (i >= 0) {
        --requires[i];
        ++k;
        int s = 1 << i;
        dfs(requires, k, b-s, s);
        dfs(requires, k, a-s, b);
    }
}

int cut(vector<int> &requires, int n, int m) {
    int ret = 0;
    int k = 0;
    for (; k < n; ++ret) {
        dfs(requires, k, m, m);
    }
    return ret;
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, m;
        cin >> n >> m;
        vector<int> requires(32, 0);
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            ++requires[tmp];
        }
        cout << "Case #" << i << ": " << cut(requires, n, m) << endl;
    }
    return 0;
}
