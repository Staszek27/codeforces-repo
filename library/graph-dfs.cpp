#include "global.cpp"

// inject here

void prep_dfs(auto& G) {
    G.prepare_triggered = true;
    G.visited.assign(G.n + 1, false);
    G.parent.assign(G.n + 1, -1);
    G.order.assign(G.n * 2 + 1, -1);
}

void dfs(auto& G, int node, int p = -1, int t = 0) {
    G.parent[node] = p;
    G.order[node] = t ++;
    for (int e : G.G[node]) {
        if (G.visited[e]) continue;
        dfs(G, e, node);
        G.order[node] = t ++;
    }
}

// inject stop

int main(){
    no_tested();
}