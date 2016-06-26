#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

typedef vector<int>::size_type sz_t;
int64_t solve(vector<int> &ps, vector<uint64_t> &ks) {
    uint64_t left = 0, right = 1000000000000000ull;
    const sz_t len = ps.size();
    if (ps.back() == 100)
        return ks.back();
    for (sz_t i = 0; i < len; ++i) {
        if (ps[i] == 0)
            continue;
        uint64_t t1 = ks[i]*100ull / ps[i];
        uint64_t t2 = ks[i]*100ull / (ps[i]+1);
        if (left < t2)
            left = t2;
        if (right > t1)
            right = t1;
    }
    if (left + 1 == right)
        return right;
    else
        return -1;
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        vector<int> ps(n);
        vector<uint64_t> ks(n);
        for (int j = 0; j < n; ++j) {
            cin >> ps[j] >> ks[j];
        }
        cout << "Case #" << i << ": " << solve(ps, ks) << endl;
    }
    return 0;
}
