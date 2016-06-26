#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double solve(int b, int l, int n) {
    vector<vector<vector<double> > > dp(2, vector<vector<double> > (l, vector<double> (l, 0)));
    dp[0][0][0] = b * 750.0;
    int cur = 0;
    for (int i = 1; i < l; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (dp[cur][j][k] > 250.0) {
                    double s = (dp[cur][j][k] - 250.0) / 3;
                    dp[1-cur][j][k] += s;
                    dp[1-cur][j+1][k] += s;
                    dp[1-cur][j+1][k+1] += s;
                    dp[cur][j][k] = 250.0;
                }
            }
        }
        for (int j = 0; j < i+1; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[cur][j][k] = 0;
                //cout << dp[1-cur][j][k] << " ";
            }
            //cout << endl;
        }
        cur = 1-cur;
    }
    int i;
    for (i = 1; i <= l; ++i) {
        if (n <= i)
            break;
        else
            n -= i;
    }
    if (dp[cur][i-1][n-1] > 250.0)
        dp[cur][i-1][n-1] = 250.0;
    //cout << cur << i << n << endl;
    return dp[cur][i-1][n-1];
}

int main(void)
{
    cout << fixed << showpoint << setprecision(7);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int b, l, n;
        cin >> b >> l >> n;
        cout << "Case #" << i << ": " << solve(b, l, n) << endl;
    }
    return 0;
}
