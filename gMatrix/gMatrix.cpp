#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int r = 0, cc = 0;
uint64_t maxElement(int row, int col, vector<int> &a, vector<int> &b, int k, int c, int x, uint64_t last) {
    uint64_t ret = 0;
    if (col == 0 || cc < col || cc >= col+k) {
        for (int i = 0, iend = k; i < iend; ++i) {
            uint64_t t = (i+row+1)*a[i+row];
            for (int j = 0, jend = iend; j < jend; ++j) {
                uint64_t tmp = (t + (j+col+1)*b[j+col] + c) % x;
                ret = max(tmp, ret);
                if (tmp == ret) {
                    if (j+col > cc) {
                        r = i+row;
                        cc = j+col;
                    }
                }
            }
        }
    } else {
        uint64_t ct = (k+col)*b[k+col-1];
        ret = last;
        for (int i = 0, iend = k; i < iend; ++i) {
            uint64_t t = (i+row+1)*a[i+row];
            uint64_t tmp = (t + ct + c) % x;
            if (tmp >= ret) {
                ret = tmp;
                if (k+col-1 > cc) {
                    r = i+row;
                    cc = k+col-1;
                }
            }
        }
    }
    return ret;
}

uint64_t solve(vector<int> &a, vector<int> &b, int k, int c, int x) {
    const int len = a.size();
    uint64_t sum = 0;
    uint64_t last = 0;
    for (int i = 0, iend = len-k+1; i < iend; ++i) {
        for (int j = 0, jend = iend; j < jend; ++j) {
            last = maxElement(i, j, a, b, k, c, x, last);
            sum += last;
        }
    }
    return sum;
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, k, c, x;
        cin >> n >> k >> c >> x;
        vector<int> a(n);
        vector<int> b(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }
        cout << "Case #" << i << ": " << solve(a, b, k, c, x) << endl;
    }
    return 0;
}
