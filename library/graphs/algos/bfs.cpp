#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here

struct BFS{
    vi depth;
    Graph&

    BFS(Graph &)
};

void prep_bfs(auto& G) {
    G.prepare_triggered = true;
    G.depth.assign(G.n + 1, -1);
}

void bfs(auto& G, int node) {
    dqi Q = {node};
    G.depth[node] = 0;
    while (!Q.empty()) {
        ll cur = Q.front();
        Q.pop_front();
        for (auto e : G[cur]) {
            if (G.depth[e] == - 1) {
                G.depth[e] = G.depth[cur] + 1;
                Q.push_back(e);
            }
        }
    }
}


// inject stop

int main(){
    no_tested();
}