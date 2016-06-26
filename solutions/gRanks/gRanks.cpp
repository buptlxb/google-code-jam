#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class myGreat: public greater<pair<int, string> > {
public:
    bool operator() (const pair<int, string> &lhs, const pair<int, string> &rhs) {
        return lhs.first > rhs.first || lhs.first == rhs.first && lhs.second < rhs.second;
    }
};

typedef vector<int>::size_type sz_t;
void solve(vector<int> &scores, map<string, vector<pair<int, int> > > &info, int m) {
    map<string, priority_queue<int> > mp;
    for (map<string, vector<pair<int, int> > >::iterator i = info.begin(), iend = info.end(); i != iend; ++i) {
        string name = i->first;
        for (sz_t j = 0, jend = i->second.size(); j < jend; ++j) {
            mp[name].push((i->second)[j].first * scores[(i->second)[j].second]);
        }
    }
    vector<pair<int, string> > final;
    for (map<string, priority_queue<int> >::iterator i = mp.begin(), iend = mp.end(); i != iend; ++i) {
        int score = 0;
        for (int j = 0; j < m && !(i->second.empty()); ++j) {
            score += i->second.top();
            i->second.pop();
        }
        final.push_back(pair<int, string>(score, i->first));
    }
    sort(final.begin(), final.end(), myGreat());
    int rank = 1;
    for (sz_t i = 0, iend = final.size(); i < iend; ++i) {
        if (i > 0 && final[i].first != final[i-1].first)
            rank = i + 1;
        cout << rank << ": " << final[i].second << endl;
    }
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int p, n, weight, m;
        string name;
        cin >> p;
        vector<int> scores(p);
        for (int j = 0; j < p; ++j)
            cin >> scores[j];
        cin >> n;
        map<string, vector<pair<int, int> > > info;
        for (int j = 0; j < n; ++j) {
            cin >> weight;
            for (int k = 0; k < p; ++k) {
                cin >> name;
                info[name].push_back(pair<int, int>(weight, k));
            }
        }
        cin >> m;
        cout << "Case #" << i << ":" << endl;
        solve(scores, info, m);
    }
    return 0;
}
