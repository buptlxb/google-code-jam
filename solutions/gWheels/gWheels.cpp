#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a%b);
}

vector<bool> solve(vector<int> &p, vector<int> &t, vector<int> &e, vector<int> &m1, vector<int> &m2) {
    vector<bool> ret(m1.size(), false);
    set<
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int np, ne, nt;
        cin >> np >> ne >> nt;
        vector<int> p(np, 0), e(ne, 0), t(nt, 0);
        for (int i = 0; i < np; ++i)
            cin >> p[i];
        for (int i = 0; i < ne; ++i)
            cin >> e[i];
        for (int i = 0; i < nt; ++i)
            cin >> t[i];
        int m;
        cin >> m;
        vector<int> m1(m, 0), m2(m, 0);
        for (int i = 0; i < m; ++i)
            cin >> m1[i] >> m2[i];
        cout << "Case #" << i << ": " << endl;
        vector<bool> ret = solve(p, e, t, m1, m2);
        for (auto b : ret)
            cout << (b ? "Yes" : "No") << endl;
    }
    return 0;
}
