#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <climits>

using namespace std;

struct Edge {
    int u, v, c;
};

vector<int> inf_road(int n, vector<Edge> &edges) {
    vector<int> tmp(n, 1000001);
    vector<vector<int> > graph(n, tmp);
    for (vector<Edge>::size_type i = 0; i < edges.size(); ++i) {
        graph[edges[i].u][edges[i].v] = min(graph[edges[i].u][edges[i].v], edges[i].c);
        graph[edges[i].v][edges[i].u] = min(graph[edges[i].v][edges[i].u], edges[i].c);
    }
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    vector<int> ret;
    for (int i = 0; i < edges.size(); ++i) {
        if (graph[edges[i].u][edges[i].v] < edges[i].c)
            ret.push_back(i);
    }
    return ret;
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges(m);
        for (int j = 0; j < m; ++j) {
            cin >> edges[j].u >> edges[j].v >> edges[j].c;
        }
        vector<int> ret = inf_road(n, edges);
        cout << "Case #" << i << ": " << endl;
        for (vector<int>::iterator k = ret.begin(), kend = ret.end(); k != kend; ++k) {
            cout << *k << endl;
        }
    }
    return 0;
}
