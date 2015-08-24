#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


int main(void)
{
    int count;
    cin >> count;
    cout << showpoint << fixed << setprecision(9);
    for (int i = 1; i <= count; ++i) {
        int n, m;
        cin >> n >> m;
        vector<int> d(n, 0);
        for (int k = 0; k < n; ++k) {
            cin >> d[k];
        }
        cout << "Case #" << i << ": " << endl;
        for (int i = 1; i <= m; ++i) {
            int l, r;
            cin >> l >> r;
            double vol = 1.0;
            for (int j = l; j <= r; j++) {
                vol *= pow(d[j], 1.0/(r-l+1));
            }
            cout << vol << endl;
        }
    }
    return 0;
}
