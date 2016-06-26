#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

struct GraphNode {
    bool color;
    bool visited;
    set<GraphNode *> adj;
    GraphNode() : color(false), visited(false) { }
};

class Graph {
    public:
        typedef vector<GraphNode *>::size_type s_t;
        void createNode(string s) {
            GraphNode *n = new GraphNode();
            m[s] = n;
            nodes.push_back(n);
        }
        bool isExit(string s) {
            auto found = m.find(s);
            if (found != m.end())
                return true;
            return false;
        }
        void addEdge(string a, string b) {
            if (!isExit(a))
                createNode(a);
            if (!isExit(b))
                createNode(b);
            m[a]->adj.insert(m[b]);
            m[b]->adj.insert(m[a]);
        }
        bool isBipartite() {
            for (s_t i = 0, iend = nodes.size(); i < iend; ++i) {
                if (nodes[i]->visited)
                    continue;
                if (!bfs(nodes[i]))
                    return false;
            }
        }
        bool bfs(GraphNode *n) {
            queue<GraphNode *> q;
            q.push(n);
            while (!q.empty()) {
                n = q.front();
                q.pop();
                n->visited = true;
                for (set<GraphNode *>::iterator i = n->adj.begin(), iend = n->adj.end(); i != iend; ++i) {
                    GraphNode *cur = *i;
                    if (!cur->visited) {
                        cur->color = !n->color;
                        q.push(cur);
                    } else if (n->color == cur->color) {
                        return false;
                    }
                }
            }
            return true;
        }
        ~Graph() {
            for (s_t i = 0, iend = nodes.size(); i < iend; ++i) {
                delete nodes[i];
            }
        }
    private:
        map<string, GraphNode*> m;
        vector<GraphNode *> nodes;
        
};

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        Graph graph;
        int pair_num;
        cin >> pair_num;
        while (pair_num) {
            string a, b;
            cin >> a >> b;
            graph.addEdge(a, b);
            --pair_num;
        }
        cout << "Case #" << i << ": " << (graph.isBipartite() ? "Yes" : "No") << endl;
    }
    return 0;
}
