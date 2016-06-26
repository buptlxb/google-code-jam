#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    const long long MOD = 1000000007;
    vector<vector<long long> > dp(100, vector<long long>(101, 0));
    for (int i = 0; i < 100; ++i)
        dp[i][0] = 1;
    for (int i = 1; i < 100; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (j+1) * (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int M, N;
        cin >> M >> N;
        cout << "Case #" << i << ": " << dp[N-1][M-1] << endl;
    }
    return 0;
}
