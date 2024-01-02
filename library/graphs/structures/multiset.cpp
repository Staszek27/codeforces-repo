#include "/Users/michal/Documents/codeforces/codeforces-repo/library/global.cpp"

// inject here

struct Graph{
    ll n, m;
    vector<msi> G;
    bool directed;

    void add_edge(ll x, ll y) {
        G[x].insert(y);
        if (!directed) 
            G[y].insert(x);
    }
    
    Graph(bool directed) {
        this->directed = directed;
        cin >> n >> m;
        G.resize(n + 1);
        for (ll i = 0; i < m; i ++) {
            ll x, y;
            cin >> x >> y;
            add_edge(x, y);
        }
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

    vi2 edges(bool double_edges = false) {
        vi2 res;
        for (int i = 0; i <= n; i ++) {
            for (auto neib : G[i]) {
                if (i <= neib || double_edges)
                    res.emplace_back(i, neib);
            }
        }
        return res;
    }

    const msi& operator[](int node) {
        return G[node];
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