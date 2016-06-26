#include <iostream>
#include <list>

using namespace std;

void solve(list<int> &cards, int k, int &ret) {
    if (ret < 3)
        return;
    if (cards.size() < 3) {
        if (ret > cards.size())
            ret = cards.size();
        return;
    }
    bool flag = false;
    list<int>::iterator c = cards.begin();
    list<int>::iterator a = c++;
    list<int>::iterator b = c++;
    list<int>::iterator iend = cards.end();
    for (; c != iend; ++a,++b,++c) {
        if (*c-*b==k && *b-*a==k) {
            list<int> tmp;
            tmp.insert(tmp.end(), cards.begin(), a);
            list<int>::iterator d = c;
            tmp.insert(tmp.end(), ++d, cards.end());
            solve(tmp, k, ret);
            flag = true;
        }
    }
    if (!flag && ret > cards.size())
        ret = cards.size();
}

int solve(list<int> &cards, int k) {
    int ret = cards.size();
    solve(cards, k, ret);
    return ret;
}


int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, k;
        cin >> n >> k;
        list<int> cards;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            cards.push_back(tmp);
        }
        cout << "Case #" << i << ": " << solve(cards, k) << endl;
    }
    return 0;
}
