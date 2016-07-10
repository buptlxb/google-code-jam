#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int C[101];
int m;

double fn(double r)
{
    double ret = 0;
    for (int i = 0; i <= m; ++i) {
        ret = ret*r + C[i];
    }
    return ret;
}

double solve()
{
    double left = 0, right = 2;
    while (right-left > 1e-12) {
        double mid = (left + right) / 2.0;
        double res = fn(mid);
        if (res == 0)
            return mid-1;
        else if (res > 0)
            left = mid;
        else
            right = mid;
    }
    return left - 1;
}

int main(void)
{
    int count;
    cin >> count;
    cout << fixed << setprecision(12);
    for (int i = 1; i <= count; ++i) {
        cin >> m;
        for (int j = 0; j <= m; ++j) {
            cin >> C[j];
        }
        C[0] = -C[0];
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    cout << flush;
    return 0;
}
