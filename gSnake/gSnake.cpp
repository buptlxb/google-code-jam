#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

struct Action {
    int x;
    char t;
};

typedef pair<int, int> Point;
typedef deque<Point> SnakeBody;

int snake(int r, int c, vector<Action> &actions) {
    SnakeBody sb;
    set<Point> s, ate;
    sb.push_back(make_pair(1,1));
    s.insert(sb.front());
    vector<Action>::size_type k = 0;
    int direct = 1; // right->1 down->2 left->3 up->4
    vector<int> row(r+1, 0);
    vector<int> col(c+1, 0);
    for (int i = 1; i <= r; ++i) {
        if (i%2)
            row[i] = c/2;
        else
            row[i] = c-c/2;
    }
    for (int i = 1; i <= c; ++i) {
        if (i%2)
            col[i] = r/2;
        else
            col[i] = r-r/2;
    }
    for (int i = 0; i <= 2000000; ++i) {
        if (k < actions.size() && actions[k].x == i) {
            if (actions[k].t == 'L') {
                direct -= 1;
                direct = direct ? direct : 4;
            } else {
                direct += 1;
                direct = direct!=5 ? direct : 1;
            }
            ++k;
        }
        Point next(sb.front());
        switch (direct) {
            case 1:
                next.second += 1;
                next.second = next.second > c ? 1 : next.second;
                break;
            case 2:
                next.first += 1;
                next.first = next.first > r ? 1 : next.first;
                break;
            case 3:
                next.second -= 1;
                next.second = next.second == 0 ? c : next.second;
                break;
            case 4:
                next.first -= 1;
                next.first = next.first == 0 ? r : next.first;
                break;
            default:
                cerr << "error" << endl;
                break;
        }
        if ((next.first+next.second) % 2 && ate.find(next) == ate.end()) {
            sb.push_front(next);
            ate.insert(next);
            row[next.first]--;
            col[next.second]--;
        } else {
            s.erase(sb.back());
            sb.pop_back();
            sb.push_front(next);
        }
        pair<set<Point>::iterator, bool> p = s.insert(next);
        if (!p.second)
            break;
        if (k == s.size()) {
            if (direct % 2 == 1 && row[sb.front().first] == 0)
                break;
            if (direct % 2 == 0 && col[sb.front().second] == 0)
                break;
        }
    }
    return sb.size();
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int s, r, c;
        cin >> s >> r >> c;
        vector<Action> actions(s);
        for (int j = 0; j < s; ++j) {
            cin >> actions[j].x >> actions[j].t;
        }
        cout << "Case #" << i << ": " << snake(r, c, actions) << endl;
    }
    return 0;
}
