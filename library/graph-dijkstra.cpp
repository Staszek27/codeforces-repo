#include "global.cpp"

// inject here


void prep_dijkstra(auto& G, ll inf_val = 1e9) {
    G.prepare_triggered = true;
    G.dist.assign(G.n + 1, inf_val);
    G.parent.assign(G.n + 1, -1);
}

void dijkstra(auto& G, int node) {
    G.dist[node] = 0;
    PQS<ti2> Q;
    Q.push({0, node});
    while (!Q.empty()) {
        auto [cur_dist, cur] = Q.top();
        Q.pop();
        if (cur_dist != G.dist[cur]) continue;
        for (auto [neib, neib_val] : G.G[cur]) {
            if (G.dist[neib] > cur_dist + neib_val) {
                G.dist[neib] = cur_dist + neib_val;
                Q.push({G.dist[neib], neib});
                G.parent[neib] = cur;
            }
        }
    }
}


// inject stop

int main(){
    no_tested();
}