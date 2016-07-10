#include <iostream>
#include <map>
#include <vector>

using namespace std;

inline int alpha(const string &tmp)
{
    int ret = 0;
    bool visit[26] = {false, };
    for (auto c : tmp) {
        if (c == ' ' || visit[c-'A'])
            continue;
        visit[c-'A'] = true;
        ++ret;
    }
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int n;
        cin >> n;
        char c;
        cin.get(c);
        string name, sname; int m = 0;
        for (int i = 0; i < n; ++i) {
            string tmp;
            getline(cin, tmp);
            int x = alpha(tmp);
            if (x > m || x == m && tmp < name) {
                name = tmp;
                m = x;
            }
        }
        cout << "Case #" << i << ": " << name << '\n';
    }
    cout << flush;
    return 0;
}
