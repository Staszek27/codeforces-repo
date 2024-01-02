#include "global.cpp"

// inject here

struct GraphWeighed{
    ll n, m;
    vector<vi2> G;
    bool weighed, directed, prepare_triggered;
    vi visited, node_val, parent, order, depth, dist, sizes;
    vi3 edges;

    void add_edge(ll x, ll y, ll w) {
        G[x].emplace_back(y, w);
        if (!directed) 
            G[y].emplace_back(x, w);
    }

    bool delete_edge(ll x, ll y, ll w) { assert(false);x;y;w; }
    
    void input() {
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y, w;
            cin >> x >> y >> w;
            add_edge(x, y, w);
        }
    }

    GraphWeighed(bool directed) {
        this->directed = directed;
        input();
    }

    ~GraphWeighed() {
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
    timer t;
    t.ok(false, "https://www.codechef.com/problems/ICL16A");
}