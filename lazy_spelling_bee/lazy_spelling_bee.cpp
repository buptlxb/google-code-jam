#include <iostream>
#include <cstdint>

using namespace std;

const uint64_t base = 1000000007;

uint64_t solve(const string &line) {
    if (line.size() < 2)
        return line.size();
    uint64_t res = 1;
    for (string::size_type i = 0, iend = line.size(); i < iend; ++i) {
        if (i == 0)
            res *= 1 + (line[i] != line[i+1]);
        else if (i+1 == iend)
            res *= 1 + (line[i] != line[i-1]);
        else {
            char a = line[i-1], b = line[i], c = line[i+1];
            if (a != b && b != c && a != c)
                res *= 3;
            else if (a == b && b == c)
                ;
            else
                res *= 2;
        }
        res %= base;
    }
    return res;
}

int main(void)
{
    int T;
    cin >> T;
    string line;
    for (int i = 1; i <= T; ++i) {
        cin >> line;
        cout << "Case #" << i << ": " << solve(line) << endl;
    }
    return 0;
}
