#include "global.cpp"

// inject here

struct GraphMultiset{
    ll n, m;
    vector<msi> G;
    bool weighed, directed, prepare_triggered;
    vi visited, node_val, parent, order, depth, dist, sizes;

    void add_edge(ll x, ll y) {
        G[x].insert(y);
        if (!directed) 
            G[y].insert(x);
    }

    bool delete_edge(ll x, ll y) {
        for (int o = 0; o < 1 + !directed; o ++) {
            auto it = G[x].lower_bound(y);
            if (it == G[x].end()) return false;
            if (*it != y) return false; 
            G[x].erase(it);
            swap(x, y);
        }
        return true;
    }
    
    void input() {
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y;
            cin >> x >> y;
            add_edge(x, y);
        }
    }

    GraphMultiset(bool directed) {
        this->directed = directed;
        input();
    }

    ~GraphMultiset() {
        assert(prepare_triggered);
    }

    void debug() {
        cout << "-------------------\n";
        cout << "Graph " << n << " nodes & " << m << " edges\n";
        for (ll i = 1; i <= n; i ++) {
            cout << i << ": { ";
            for (auto x : G[i]) {
                cout << x << " ";
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