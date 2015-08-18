#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    typedef vector<pair<string, string> >::size_type s_t;
    bool canSplit(vector<pair<string, string> > &trouble_pairs) {
        set<string> s1, s2;
        return canSplit(trouble_pairs, 0, s1, s2);
    }
    bool canSplit(vector<pair<string, string> > &trouble_pairs, s_t start, set<string> &s1, set<string> &s2) {
        if (start == trouble_pairs.size())
            return true;
        auto a = trouble_pairs[start].first;
        auto b = trouble_pairs[start].second;
        bool a1 = s1.find(a) == s1.end();
        bool a2 = s2.find(a) == s2.end();
        bool b1 = s1.find(b) == s1.end();
        bool b2 = s2.find(b) == s2.end();
        if (a1 && b2) {
            s2.insert(a);
            s1.insert(b);
            if (canSplit(trouble_pairs, start+1, s1, s2))
                return true;
            if (a2)
                s2.erase(a);
            if (b1)
                s1.erase(b);
        }
        if (a2 && b1) {
            s1.insert(a);
            s2.insert(b);
            if (canSplit(trouble_pairs, start+1, s1, s2))
                return true;
            if (a1)
                s1.erase(a);
            if (b2)
                s2.erase(b);
        }
        return false;
    }
};

int main(void)
{
    int count;
    Solution slu;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int pair_num;
        cin >> pair_num;
        vector<pair<string, string> > trouble_pairs;
        while (pair_num) {
            pair<string, string> p;
            cin >> p.first >> p.second;
            trouble_pairs.push_back(p);
            --pair_num;
        }
        cout << "Case #" << i << ": " << (slu.canSplit(trouble_pairs) ? "Yes" : "No") << endl;
    }
    return 0;
}
