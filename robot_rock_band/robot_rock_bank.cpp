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

void build(vector<int> &v)
{
    for (auto x : v) {
        TrieNode *cur = root;
        for (int i = 0; i < 32; ++i) {
            int idx = (x & (1 << i)) != 0;
            if (cur->children[idx] == nullptr)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->num += 1;
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

long long solve(vector<int> &A, vector<int> &B, int k)
{
    long long ret = 0;
    for (int i = 0; i < A.size(); ++i) {
        ret += query(k^A[i]);
    }
    return ret;
}

long long solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, int k)
{
    build(D);
    long long ret = 0;
    unordered_map<int, long long> dict;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            int t = A[i] ^ B[j] ^ k;
            if (dict.find(t) != dict.end())
                ret += dict[t];
            else {
                dict[t] = solve(C, D, A[i]^B[j]^k);
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
        vector<vector<int>> robots(4, vector<int>(n));
        for (int j = 0; j < robots.size(); ++j) {
            for (int k = 0; k < robots[j].size(); ++k) {
                cin >> robots[j][k];
            }
        }
        cout << "Case #" << i << ": " << solve(robots[0], robots[1], robots[2], robots[3], k) << '\n';
    }
    cout << flush;
    return 0;
}
