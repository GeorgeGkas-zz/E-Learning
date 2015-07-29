
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class Graph {
  int V;
  list<int> *adj;
  public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isReachable(int s) {

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
 
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            // If this adjacent node is the destination node, then return true
            if (*i == adj[s].end()) return true;
 
            // Else, continue to do BFS
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return false;
}

int main() {
  int n;
  scanf("%d", &n);
  Graph G(n);

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    G.addEdge(a, b); G.addEdge(b, a); // double connected rode
  }

  bool isAllConnected = false;

  for (int i = 0; i < n; i++) {
    if (G.isReachable(i)) {
        isAllConnected = true;
    }
    else {
        isAllConnected = false;
        break;
    }
  }

  if (isAllConnected == true) printf("0\n");
  else printf("1\n");

  return 0;
}
