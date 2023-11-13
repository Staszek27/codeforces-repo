#include "global.cpp"

// inject here

void prep_dsu(auto& G) {
    G.prepare_triggered = true;
    G.parent.assign(G.n + 1, 0);
    G.sizes.assign(G.n + 1, 0);
    for (int i = 1; i <= G.n; i ++) 
        G.parent[i] = i;
}

int fart(auto& G, int node) {
    return (
        G.parent[node] == node ? 
            node : 
            (G.parent[node] = fart(G, node))
    );
}

bool onion(auto& G, int x, int y) {
    x = fart(G, x); y = fart(G, y);
    if (x == y) return false;
    if (G.sizes[x] < G.sizes[y]) swap(x, y);
    G.sizes[x] += G.sizes[y];
    G.parent[y] = x;
    return true;
}

void prep_kruskal(auto& G) {
    assert(!G.directed);
    G.prepare_triggered = true;
    
    for (int i = 1; i <= G.n; i ++)
        for (auto [x, y] : G[i])
            if (i <= x)
                G.edges.emplace_back(y, i, x);
    sort(G.edges.begin(), G.edges.end());
    prep_dsu(G);
}

vi3 kruskal(auto& G) {
    vi3 res;
    for (auto [w, x, y] : G.edges)
        if (onion(G, x, y)) res.emplace_back(x, y, w);
    return res;
}

// inject stop

int main(){
    no_tested();
}