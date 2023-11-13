#include "global.cpp"

// inject here


struct GraphMultisetWeighed{
    ll n, m;
    vector<msi2> G;
    bool weighed, directed, prepare_triggered;
    vi visited, node_val, parent, order, depth, dist, sizes;
    vi3 edges;

    void add_edge(ll x, ll y, ll w) {
        G[x].insert({y, w});
        if (!directed) 
            G[y].insert({x, w});
    }

    bool delete_edge(ll x, ll y, ll w) {
        for (int o = 0; o < 1 + !directed; o ++) {
            ti2 p = {y, w};
            auto it = G[x].lower_bound(p);
            if (it == G[x].end()) return false;
            if (*it != p) return false; 
            G[x].erase(it);
            swap(x, y);
        }
        return true;
    }

    void input() {
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y, w;
            cin >> x >> y >> w;
            add_edge(x, y, w);
        }
    }

    GraphMultisetWeighed(bool directed) {
        this->directed = directed;
        input();
    }

    ~GraphMultisetWeighed() {
        assert(prepare_triggered);
    }

    void debug() {
        cout << "-------------------\n";
        cout << "Graph " << n << " nodes & " << m << " edges\n";
        for (ll i = 1; i <= n; i ++) {
            cout << i << ": { ";
            for (auto [x, y] : G[i]) {
                cout << x << "(" <<  y << ") ";
            }
            cout << " }\n";
        }
        cout << "-------------------\n";
    }
};

// inject stop

int main(){
    no_tested();
}