#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
    int num;
    TrieNode *children[2];
    TrieNode () : num(0) {
        children[0] = nullptr;
        children[1] = nullptr;
    }
    void reset() { num = 0; children[0] = nullptr; children[1] = nullptr;}
} dummy, *root = &dummy;

void build(unordered_map<int, int> &v)
{
    for (auto m : v) {
        int x = m.first;
        TrieNode *cur = root;
        for (int i = 0; i < 32; ++i) {
            int idx = (x & (1 << i)) != 0;
            if (cur->children[idx] == nullptr)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->num = m.second;
    }
}

int query(int x)
{
    TrieNode *cur = root;
    for (int i = 0; i < 32; ++i) {
        int idx = (x & (1 << i)) != 0;
        if (cur->children[idx] == nullptr)
            return 0;
        cur = cur->children[idx];
    }
    return cur->num;
}

void destory(TrieNode *root)
{
    if (!root)
        return;
    if (root->children[0])
        destory(root->children[0]);
    if (root->children[1])
        destory(root->children[1]);
    delete root;
}

long long solve(unordered_map<int, int> &A, unordered_map<int, int> &B, int k)
{
    long long ret = 0;
    for (auto a : A) {
        ret += a.second * query(k^a.first);
    }
    return ret;
}

long long solve(unordered_map<int, int> &A, unordered_map<int, int> &B, unordered_map<int, int> &C, unordered_map<int, int> &D, int k)
{
    build(D);
    long long ret = 0;
    unordered_map<int, long long> dict;
    for (auto a : A) {
        for (auto b : B) {
            int t = a.first ^ b.first ^ k;
            if (dict.find(t) != dict.end())
                ret += dict[t];
            else {
                dict[t] = a.second * b .second * solve(C, D, t);
                ret += dict[t];
            }
        }
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        destory(root->children[0]);
        destory(root->children[1]);
        root->reset();
        int n, k;
        cin >> n >> k;
        vector<unordered_map<int, int>> robots(4, unordered_map<int, int>());
        for (int j = 0; j < robots.size(); ++j) {
            for (int k = 0; k < n; ++k) {
                int r;
                cin >> r;
                ++robots[j][r];
            }
        }
        cout << "Case #" << i << ": " << solve(robots[0], robots[1], robots[2], robots[3], k) << '\n';
    }
    cout << flush;
    return 0;
}
