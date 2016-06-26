#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

long double solve(int n, int x, int k, int a, int b, int c)
{
    unordered_map<int, long double> prev;
    prev[x] = 1;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, long double> cur;
        for (auto m : prev) {
            int y = m.first;
            int ax = y & k;
            int bx = y | k;
            int cx = y ^ k;
            cur[ax] += m.second * a/100.0;
            cur[bx] += m.second * b/100.0;
            cur[cx] += m.second * c/100.0;
        }
        swap(prev, cur);
    }
    long double ret = 0.0;
    for (auto m : prev) {
        ret += m.first * m.second;
    }
    return ret;
}

int main(void)
{
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for (int i = 1; i <= t; ++i) {
        int n, x, k, a, b, c;
        cin >> n >> x >> k >> a >> b >> c;
        cout << "Case #" << i << ": " << solve(n, x, k, a, b, c) << endl;
    }
    return 0;
}
